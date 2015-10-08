
#ifndef _TextureUtils_h_
#define _TextureUtils_h_

#include "im360/core/MarbleConfig.h"
#include "ITexture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace texture {

    struct FragmentOptions
	{
		float cropBottom;
	};
	
    struct YUVSeperated
	{
		unsigned char * y;
		unsigned char * u;
		unsigned char * v;
		unsigned int yStride;
		unsigned int uStride;
		unsigned int vStride;
		unsigned int width;
		unsigned int height;
	};

	I3DAPI void copyYUV420ToRGB888(const YUVSeperated & yuv, unsigned char * rgb, unsigned int width, unsigned int height);
	I3DAPI void copyYUV420ToRGB565(const YUVSeperated & yuv, unsigned char * rgb, unsigned int width, unsigned int height);

	I3DAPI void copyYUV444ToRGB888(const YUVSeperated & yuv, unsigned char * rgb, unsigned int width, unsigned int height);
	I3DAPI void copyYUV444ToRGB565(const YUVSeperated & yuv, unsigned char * rgb, unsigned int width, unsigned int height);

	I3DAPI void copyYUVToYUV(const YUVSeperated & yuv, unsigned char * y, unsigned char * u, unsigned char * v, unsigned int width, unsigned int height);
	I3DAPI void copyYUVToLinearYUV(const YUVSeperated & yuv, unsigned char * yuvData, unsigned int width, unsigned int height);

	I3DAPI std::string getFragmentSource(TextureFormat format, FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_1_YUV420(FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_3_YUV420(FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_3_YUV420_anaglyphRed(FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_3_YUV420_anaglyphBlue(FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_6_YUV420_anaglyph(FragmentOptions * options=NULL);
	I3DAPI std::string getFragmentSourceTF_1_RGB(FragmentOptions * options=NULL);

}}
#endif
#endif
