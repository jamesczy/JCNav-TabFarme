#ifndef _MultiScreen_h_
#define _MultiScreen_h_

#include "CubeScreen.h"
#include "PlanarScreen.h"
#include "SphereScreen.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace screen {

    class I3DAPI MultiScreen : virtual public ScreenBase
    {
    public:
        enum ScreenType
        {
            SPHERICAL,
            PLANAR,
            CUBICAL
        };

        typedef core::SharedPointer<MultiScreen>::pointer pointer;
        virtual ~MultiScreen();

        static MultiScreen::pointer create();
        static MultiScreen::pointer create(ScreenType type);

        virtual std::string getClassName() const;

        ScreenType getScreenType();
        void setScreenType(ScreenType type);

        SphereScreen::pointer getSphere();
        PlanarScreen::pointer getPlane();
        CubeScreen::pointer getCube();

        void setFillMode(core::FillModeType::Type fillMode);
        core::FillModeType::Type getFillMode();

        // ScreenBase
        virtual void setTexture(texture::Texture::pointer texture);
        scene::ModelNode::pointer getModelNode();

        // Node
        void update(const math::matrix & worldTransform);

        // IJsonHandler
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

    protected:
        MultiScreen();
        virtual bool init(ScreenType type);

    private:
        SphereScreen::pointer       _sphere;
        PlanarScreen::pointer       _plane;
        CubeScreen::pointer         _cube;
        ScreenBase::pointer         _current;

        ScreenType                  _type;
    };

}}

#endif
#endif
