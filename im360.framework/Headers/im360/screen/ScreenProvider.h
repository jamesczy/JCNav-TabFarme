/*
 *  ScreenProvilder.h
 *  libim360
 *
 *  Created by Ben Siroshton on 8/5/13.
 *  Copyright 2013 Immersive Media. All rights reserved.
 *
 */

#ifndef _ScreenProvider_h_
#define _ScreenProvider_h_

#include "im360/core/MarbleConfig.h"
#include "im360/core/I3dObject.h"
#include "im360/util/Singleton.h"
#include "im360/screen/IScreen.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
    namespace screen {
        
        class I3DAPI ScreenProvider : virtual public core::I3dObject, virtual public im360::util::Singleton<ScreenProvider>
        {
        friend class im360::util::Singleton<ScreenProvider>;
        public:
			typedef core::SharedPointer<ScreenProvider>::pointer pointer;
            virtual ~ScreenProvider();
            virtual std::string getClassName() const;

            screen::IScreen::pointer buildScreenFromMeta(const std::string & json);
            screen::IScreen::pointer buildScreenForProjection(core::MediaProjection::Projection projection);
            
        protected:
            ScreenProvider();
            
        };
        
    }}
#endif
#endif
