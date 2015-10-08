/*
 *  MeshData.h
 *  player
 *
 *  Created by Ben Siroshton on 8/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _MeshData_h_
#define _MeshData_h_

#include "im360/core/MarbleConfig.h"
#include "im360/math/Bounds3.h"
#include "im360/resource/Resource.h"
#include "im360/core/Pointer.h"
#include "RenderElement.h"
#include "IndexBuffer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <list>
namespace im360 {
namespace mesh {
	
    class I3DAPI MeshData : virtual public core::I3dObject, virtual public resource::Resource
	{
	public:
        typedef core::SharedPointer<MeshData>::pointer pointer;
		
        static MeshData::pointer create();
        
		virtual ~MeshData();
        virtual std::string getClassName() const;
		
        void addVertexElement(RenderElement::pointer element);
		unsigned int getVertexElementCount();
		
        RenderElement::pointer getVertexElement(unsigned int index);
        RenderElement::pointer getVertexElementByName(std::string name);
        RenderElement::pointer removeVertexElement(unsigned int index);

		unsigned int getVertexElementBufferSizeTotal();
		unsigned int getVertexElementStrideTotal();

        void setIndexBuffer(IndexBuffer::pointer ib);
        IndexBuffer::pointer getIndexBuffer();
		
		void updateVertexBuffer();
		void updateIndexBuffer();

		void drawElements();

        // IResource interface
        virtual resource::IResource::RestoreResult restoreResource(unsigned int restoreCount);

    protected:
        MeshData();
        virtual bool init();
        
	private:
		// Vertex Elements
        typedef std::list<RenderElement::pointer>	VertexElementList;
        typedef VertexElementList::iterator         VertexElementListIt;
		
		VertexElementList	_elements;

		unsigned int	_glVB;
		unsigned int	_glVBSize;
		unsigned char *	_VBBuffer;
		
		// Indices
        IndexBuffer::pointer	_indexBuffer;
		
		unsigned int	_glIB;
		unsigned int	_glIBSize;
				
	};
	
}}
#endif
#endif

