#ifndef _CubeNode_h_
#define _CubeNode_h_

#include "SimpleModelNode.h"
#include "im360/component/BoxShape.h"
#include "im360/math/Rect.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace scene {

    class I3DAPI CubeNode : virtual public SimpleModelNode
    {
    public:
        typedef core::SharedPointer<CubeNode>::pointer pointer;

        static CubeNode::pointer create();
        static CubeNode::pointer create(float radius, int cols = 3, int rows = 2, std::string order = "LFRBDU");
        
        virtual ~CubeNode();
        virtual std::string getClassName() const;

        virtual void setMesh(float radius, int cols = 3, int rows = 2, std::string order = "LFRBDU");

        virtual void handleJsonProperty(std::string name, std::string value, json::JsonInfo & json);
        virtual void jsonPropertiesEnd();

    protected:
        CubeNode();
        void init(float radius=1.f, int cols = 3, int rows = 2, std::string order = "LFRBDU");

        void setBuildProperties(float radius, int cols, int rows, std::string order = "LFRBDU");

        virtual mesh::MeshData::pointer buildMesh();
        virtual component::CollisionObject::pointer getShape();

        struct{
            float                   radius;
            int                     rows;
            int                     cols;
            std::string             order;
        } _build;

        component::BoxShape::pointer    _boxShape;

        virtual void updateBounds();

    };

}}
#endif
#endif
