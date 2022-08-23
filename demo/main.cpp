#include <spdlog/spdlog.h>
#include "RenderHelp/RenderHelp.h"

int main(){
    spdlog::set_level(spdlog::level::debug);
    SPDLOG_DEBUG("begin");
    RenderHelp rh(800, 600);
	const int VARYING_COLOR = 0;    // 定义一个 varying 的 key

	Vec3f eye_pos = {0, -0.5, 1.7};
	Vec3f eye_at = {0, 1, 0};
	Vec3f eye_up = {0, 1, 0};
	
	float perspective = 3.1415926f * 0.5f;

	Mat4x4f mat_model = matrix_set_scale(1, 1, 1);
	Mat4x4f mat_view = matrix_set_lookat(eye_pos, eye_at, eye_up);
	Mat4x4f mat_proj = matrix_set_perspective(perspective, 6 / 8.0, 1.0, 500.0f);
	Mat4x4f mat_mvp = mat_model * mat_view * mat_proj;

	struct { Vec3f pos; Vec4f color; } vs_input[3] = {
		{ {  -0.5,  0.0, 0.0}, {1, 0, 0, 1} },
		// { { -0.5, 0.0, 0.0, 1}, {0, 1, 0, 1} },
		{ { +0.5, 0.0, 0.0}, {0, 0, 1, 1} },
	};

    rh.SetRenderState(true, false);

	// 顶点着色器，初始化 varying 并返回坐标，
	// 参数 index 是渲染器传入的顶点序号，范围 [0, 2] 用于读取顶点数据
	rh.SetVertexShader([&] (int index, ShaderContext& output) -> Vec4f {
			// output.varying_vec4f[VARYING_COLOR] = vs_input[index].color;
			// return vs_input[index].pos;		// 直接返回坐标
			// Vec4f pos = vs_input[index].pos.xyz1();
			Vec4f pos = vs_input[index].pos.xyz1() * mat_mvp;
			SPDLOG_INFO("{} => {}", vector_repr(vs_input[index].pos), vector_repr(pos));
			return pos;
		});

	// 像素着色器，返回颜色
	rh.SetPixelShader([&] (ShaderContext& input) -> Vec4f {
			return input.varying_vec4f[VARYING_COLOR];
		});
    // rh.DrawPrimitive();
	bool res = rh.DrawLine();
	if(!res){
		SPDLOG_ERROR("DrawLine error");
	}else{
		SPDLOG_INFO("DrawLine success");
	}
    rh.SaveFile("outputbbb.bmp");
	SPDLOG_INFO("save outputaaa");
    return 0;
}