#include "textureformats.hpp"

namespace gl
{
	const unsigned int TextureFormatToGLSizedInternal[static_cast<unsigned int>(TextureFormat::NUM_FORMATS)] =
	{ GL_R8, GL_R8_SNORM, GL_R16, GL_R16_SNORM, GL_RG8, GL_RG8_SNORM, GL_RG16, GL_RG16_SNORM, GL_R3_G3_B2, GL_RGB4, GL_RGB5, GL_RGB8, GL_RGB8_SNORM, GL_RGB10, GL_RGB12,
	GL_RGB16_SNORM, GL_RGBA2, GL_RGBA4, GL_RGB5_A1, GL_RGBA8, GL_RGBA8_SNORM, GL_RGB10_A2, GL_RGB10_A2UI, GL_RGBA12, GL_RGBA16, GL_SRGB8, GL_SRGB8_ALPHA8, GL_R16F,
	GL_RG16F, GL_RGB16F, GL_RGBA16F, GL_R32F, GL_RG32F, GL_RGB32F, GL_RGBA32F, GL_R11F_G11F_B10F, GL_RGB9_E5, GL_R8I, GL_R8UI, GL_R16I, GL_R16UI, GL_R32I, GL_R32UI,
	GL_RG8I, GL_RG8UI, GL_RG16I, GL_RG16UI, GL_RG32I, GL_RG32UI, GL_RGB8I, GL_RGB8UI, GL_RGB16I, GL_RGB16UI, GL_RGB32I, GL_RGB32UI, GL_RGBA8I, GL_RGBA8UI, GL_RGBA16I,
	GL_RGBA16UI, GL_RGBA32I, GL_RGBA32UI };

	const unsigned int TextureFormatToGLBaseInternal[static_cast<unsigned int>(TextureFormat::NUM_FORMATS)] =
	{ GL_RED, GL_RED, GL_RED, GL_RED, GL_RG, GL_RG, GL_RG, GL_RG, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGB, GL_RGBA, GL_RGBA, GL_RGBA,
	 GL_RGBA, GL_RGBA, GL_RGBA, GL_RGBA, GL_RGB, GL_RGBA, GL_RED, GL_RG, GL_RGB, GL_RGBA, GL_RED, GL_RG, GL_RGB, GL_RGBA, GL_RGB, GL_RGB, GL_RED_INTEGER, GL_RED_INTEGER,
	 GL_RED_INTEGER, GL_RED_INTEGER, GL_RED_INTEGER, GL_RED_INTEGER, GL_RG_INTEGER, GL_RG_INTEGER, GL_RG_INTEGER, GL_RG_INTEGER, GL_RG_INTEGER, GL_RG_INTEGER, GL_RGB_INTEGER,
	 GL_RGB_INTEGER, GL_RGB_INTEGER, GL_RGB_INTEGER, GL_RGB_INTEGER, GL_RGB_INTEGER, GL_RGBA_INTEGER, GL_RGBA_INTEGER, GL_RGBA_INTEGER, GL_RGBA_INTEGER, GL_RGBA_INTEGER, GL_RGBA_INTEGER };

	const unsigned int ImageFormatToGLImageUnit[static_cast<unsigned int>(TextureFormat::NUM_FORMATS)] =
	{ GL_RGBA32F, GL_RGBA16F, GL_RG32F, GL_RG16F, GL_R11F_G11F_B10F, GL_R32F, GL_R16F, GL_RGBA32UI, GL_RGBA16UI, GL_RGB10_A2UI, GL_RGBA8UI, GL_RG32UI, GL_RG16UI, GL_RG8UI, 
	GL_R32UI, GL_R16UI, GL_R8UI, GL_RGBA32I, GL_RGBA16I, GL_RGBA8I, GL_RG32I, GL_RG16I, GL_RG8I, GL_R32I, GL_R16I, GL_R8I, GL_RGBA16, GL_RGB10_A2, GL_RGBA8, GL_RG16, GL_RG8, 
	GL_R16, GL_R8, GL_RGBA16_SNORM, GL_RGBA8_SNORM, GL_RG16_SNORM, GL_RG8_SNORM, GL_R16_SNORM, GL_R8_SNORM };
}