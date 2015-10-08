/*
 *  VideoEntity.h
 *  im360lib
 *
 *  Created by Ben Siroshton on 05/31/11.
 *  Copyright 2011 Immersive Ventures. All rights reserved.
 *
 */
#ifndef _VideoEntity_h_
#define _VideoEntity_h_

#include "im360/core/MarbleConfig.h"
#include "IEntity.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace ws {
namespace entities {

    class I3DAPI VideoEntity : virtual public IEntity
	{
	public:
        typedef core::SharedPointer<VideoEntity>::pointer pointer;

		long        sourceId;
		long		videoId;
		std::string	videoPath;
		std::string	videoFile;
		long		videoFilesize;
		std::string videoUrl;
		std::string	videoFormat;
		int			videoWidth;
		int			videoHeight;
		long		videoBitrate;
		std::string videoCodec;
		float		videoFps;
		float		videoDuration;
		int			videoAudioChannels;
		long		videoAudioBitrate;
		long		videoAudioFrequency;
		std::string	videoAudioCodec;
		std::string	videoDateAdded;
		std::string	videoDateUpdated;
		// source merged fields
		std::string	videoName;
		std::string	videoThumb;
		std::string	videoThumbUrl;
		std::string	videoThumb2x;
		std::string	videoThumb2xUrl;
		std::string	videoKeywords;
		std::string	videoDescription;
		std::string	videoCity;
		std::string	videoState;
		std::string	videoZip;
		std::string	videoCountry;
		double		videoLatitude;
		double		videoLongitude;
		std::string videoMetaComment;
		std::string videoExternalUrl;

        static VideoEntity::pointer create();
        
		virtual ~VideoEntity();
        virtual std::string getClassName() const;

		virtual void clear();

        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

		virtual std::string getJson() const;
		virtual void parseJson(std::string json);

    protected:
		VideoEntity();
        virtual bool init();

	};

}}}
#endif
#endif
