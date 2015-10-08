
#ifndef _Node_h_
#define _Node_h_

#include "im360/core/MarbleConfig.h"
#include "im360/util/TypeList.h"
#include "im360/math/MathUtils.h"
#include "im360/math/Transform.h"
#include "im360/math/Bounds3.h"
#include "im360/json/IJsonHandler.h"
#include "IRenderable.h"
#include "im360/component/ComponentBase.h"
#include "im360/math/ITransformListener.h"
#include "im360/core/Pointer.h"
#include "im360/event/EventDispatcher.h"
#include "im360/util/Command.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace scene {

    class Scene;

    class I3DAPI Node : virtual public util::TypeList<component::ComponentBase::pointer>, virtual public math::Transform
	{
    friend class Scene;

	public:
        typedef core::SharedPointer<Node>::pointer pointer;
        typedef core::WeakPointer<Node>::pointer weakPointer;

        enum ProjectionMode
        {
            PROJECTION_NORMAL,
            PROJECTION_VIEWPLANE,
            PROJECTION_SCREEN
        };
        
        typedef std::list<Node::pointer> NodeList;
        typedef std::list<Node::pointer>::iterator NodeListIterator;

        static Node::pointer create();
        
		virtual ~Node();
        virtual std::string getClassName() const;

		int findNodes(NodeList & nodes, const std::string & name);
		
        core::WeakPointer<Scene>::pointer getScene();
		
        math::matrix getWorldTransform();

        math::Bounds3 getBounds();

		bool getIsVisible();
		virtual void setIsVisible(bool visible);

        ProjectionMode getProjectionMode();
        void setProjectionMode(ProjectionMode mode);
        
        float getAlpha();
        void setAlpha(float alpha);
        
        virtual void update(const math::matrix & worldTransform);
		virtual void render();

        void setUserData(void * data);
        void * getUserData();
        
        // IJsonHandler
        virtual void jsonPropertiesStart();
        virtual void handleJsonNode(std::string name, json::JsonInfo & json);
        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

        // child/parent support
        core::WeakPointer<Node>::pointer getParent();
        void bringToFront();
        void pushToBack();
        bool addChild(Node::pointer node, int atPos=-1);
        void removeFromParent();
        void removeChild(Node::pointer node);
        void removeChildAt(unsigned long index);
        bool hasChild(Node::pointer node);
        Node::pointer getChildAt(unsigned long index);
        void removeChildren(bool recursive=false);
        unsigned long getChildCount();

        // TypeList helpers
        template<typename T> std::tr1::shared_ptr<T> findFirstItem()
        {
            util::TypeList<component::ComponentBase::pointer>::ListIterator it = begin();
            while(it!=end())
            {
                std::tr1::shared_ptr<T> item = std::tr1::dynamic_pointer_cast<T>(*it);
                if( item ) return item;
                ++it;
            }

            return std::tr1::shared_ptr<T>();
        }

        template<typename T> void removeItems()
        {
            util::TypeList<component::ComponentBase::pointer>::ListIterator it = begin();
            while(it!=end())
            {
                std::tr1::shared_ptr<T> item = std::tr1::dynamic_pointer_cast<T>(*it);
                if( item ) it = erase(it);
                else ++it;
            }
        }

        // I3dObject
        virtual util::Variant evaluate(const util::Command & command);
        
	protected:
        Node();
        virtual bool init();

        float getAbsoluteAlpha();
        
        virtual void childNodeAdded(Node::pointer node);
        virtual void childNodeRemoved(Node::pointer node);

        virtual void onAddedToScene(core::WeakPointer<Scene>::pointer scene);
        virtual void onRemovedFromScene(core::WeakPointer<Scene>::pointer scene);
		
        virtual void onItemAdded(component::ComponentBase::pointer item);
        virtual void onItemRemoved(component::ComponentBase::pointer item);

        virtual void setBounds(math::Bounds3 bounds);

		virtual void onPositionChange();
		virtual void onScaleChange();
		virtual void onRotationChange();
        virtual void onAlphaChange();

        virtual void updateBounds();

        virtual void innerJson(json::JsonStringBuilder & json) const;
        virtual void innerJson(im360::json::JsonStringBuilder & json, bool includeChildren) const;

        void setScene(core::WeakPointer<Scene>::pointer scene);

    private:
        static unsigned long                _idCounter;
        core::WeakPointer<Scene>::pointer   _scene;
        bool                                _isVisible;
        ProjectionMode                      _projectionMode;
        float                               _alpha;
        math::matrix                        _worldTransform; // NOTE: look into changing this to im360::math::Transform
        bool                                _scaleChanged;
        math::Bounds3                       _bounds;
        void *                              _userData;

         // child/parent support
        core::WeakPointer<Node>::pointer    _parent;
        NodeList                            _children;

    };

}}
#endif

// -----------------------------------------------------------------------
// C Interface
// -----------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

I3DAPI long I3dNode_new();
I3DAPI void I3dNode_delete(long handle);

#ifdef __cplusplus
}
#endif

#endif

