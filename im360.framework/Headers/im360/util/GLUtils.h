/*
 * GLUtils.h
 *
 *  Created on: Nov 30, 2011
 *      Author: Ben Siroshton
 */

#ifndef _GLUtils_h_
#define _GLUtils_h_

#ifndef GL_IMG_texture_stream
#define GL_TEXTURE_STREAM_IMG						0x8C0D
#define GL_TEXTURE_NUM_STREAM_DEVICES_IMG			0x8C0E
#define GL_TEXTURE_STREAM_DEVICE_WIDTH_IMG			0x8C0F
#define GL_TEXTURE_STREAM_DEVICE_HEIGHT_IMG			0x8EA0
#define GL_TEXTURE_STREAM_DEVICE_FORMAT_IMG			0x8EA1
#define GL_TEXTURE_STREAM_DEVICE_NUM_BUFFERS_IMG	0x8EA2
#define GL_TEXTURE_BINDING_STREAM_IMG				0x9131
#endif

#include "im360/core/MarbleTypes.h"

#ifdef __cplusplus
#include <string>
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace gl {

	bool init_GL_IMG_texture_stream();
	void glTexBindStreamIMG(int device, int deviceoffset);
	void glGetTexStreamDeviceAttributeivIMG(int target, int pname, int * params);
	const char * glGetTexStreamDeviceNameIMG(int target);
    bool saveFrameBufferToFile(int frameBufferWidth, int frameBufferHeight, const std::string & file, const core::ImageFormat::Format format);
    long getCurrentContext();
    void debugPrintState();

}}
#endif
#endif

