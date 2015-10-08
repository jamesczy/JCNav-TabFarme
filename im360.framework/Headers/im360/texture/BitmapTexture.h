/*
 *  BitmapTexture.h
 *  marble360
 *
 *  Created by Ben Siroshton on 11/5/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _BitmapTexture_h_
#define _BitmapTexture_h_

#include "im360/core/MarbleConfig.h"
#include "im360/resource/Resource.h"
#include "im360/core/Pointer.h"
#include "im360/net/DownloadQueue.h"
#include "im360/event/EventListener.h"
#include "im360/event/EventDispatcher.h"

#include "Texture.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace texture {

    enum ImageType
	{
		IMG_BMP,
		IMG_PNG,
        IMG_JPG
	};
		
    class I3DAPI BitmapTexture : virtual public event::EventListener, virtual public event::EventDispatcher, virtual public Texture, virtual public resource::Resource
	{
	public:
        typedef core::SharedPointer<BitmapTexture>::pointer pointer;

		static BitmapTexture::pointer create();
        
        virtual ~BitmapTexture();
        virtual std::string getClassName() const;

		virtual bool bindTexture(unsigned int textureSlot=0);
		
        virtual bool loadImageFromUrl(std::string url, bool async=false);
		virtual bool loadImageFromMemory(ImageType type, const unsigned char * image, unsigned int size);
		virtual bool loadFromRaw(unsigned int width, unsigned int height, const unsigned char * data, TextureFormat format);
        
		virtual unsigned int getWidth();
		virtual unsigned int getHeight();
		virtual TextureFormat getFormat();
		
		virtual bool getIsPOW2();

        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);

        virtual void cancelAsyncLoad();
        
        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
        BitmapTexture();
        virtual bool init();
        
        // EventListener
        virtual void onEvent(event::Event::pointer event);

	private:
		struct
		{
			unsigned char * data;
			unsigned long	dataSize;
            bool            ownsData;
			unsigned int    glTex;
            bool            hasGlTex;
			unsigned int	width;
			unsigned int	height;
			int				glFormat;
			TextureFormat	format;            
            bool            needsUpdate;
		} _texture;

        async::Mutex                _textureMutex;
        net::DownloadQueue::pointer _downloader;

		void createTextureFromDevIL();
		bool dataToGl();
		void releaseSystemMemory();

        virtual bool loadImageFromFile(std::string file);
	};

}}
#endif
#endif
