/*
 *  ProgramProvilder.h
 *  libim360
 *
 *  Created by Ben Siroshton on 8/5/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _RenderEffectProvider_h_
#define _RenderEffectProvider_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "im360/util/Singleton.h"
#include "im360/texture/ITexture.h"
#include "RenderEffect.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
    namespace render {
        
        class I3DAPI RenderEffectProvider : virtual public core::I3dObject, virtual public im360::util::Singleton<RenderEffectProvider>
        {
        friend class im360::util::Singleton<RenderEffectProvider>;
        public:
            virtual ~RenderEffectProvider();
            virtual std::string getClassName() const;

            RenderEffect::pointer getEffect(texture::TextureFormat textureFormat, std::string vertexShader = "xyz_uv_1tex.vsh");

        protected:
            RenderEffectProvider();
            
        };
        
    }}
#endif
#endif
