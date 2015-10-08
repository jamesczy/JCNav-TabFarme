/*
 *  RenderElement.h
 *  player
 *
 *  Created by Ben Siroshton on 8/10/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _RenderElement_h_
#define _RenderElement_h_

#include "im360/core/MarbleConfig.h"
#include "DataBuffer.h"
#include "im360/core/Pointer.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
#include <string>
namespace im360 {
namespace mesh {
	
	enum RenderElementType
	{
		VERTEX_BUFFER,
		INDEX_BUFFER,
        UV_BUFFER
	};
	
	class I3DAPI RenderElement : virtual public DataBuffer
	{		
	public:
        typedef core::SharedPointer<RenderElement>::pointer pointer;
		
        static RenderElement::pointer create(RenderElementType type, unsigned int elementSize, unsigned int componentCount, unsigned int componenetSize, int glType);
        
		virtual ~RenderElement();
        virtual std::string getClassName() const;

		std::string getElementName();
		void setElementName(std::string name);

		int getElementAttribIndex();
        int getElementAttribIndex() const;
        void setElementAttribIndex(int index);
		
		RenderElementType getElementType();
		
		void setElementCount(unsigned int count);
		unsigned int getElementCount();
        unsigned int getElementCount() const;
        unsigned int getElementSize();
        unsigned int getElementSize() const;
        unsigned int getElementCapacity();
        unsigned int getElementCapacity() const;
        unsigned int getComponentCount();
        unsigned int getComponentCount() const;
        unsigned int getComponentSize();
        unsigned int getComponentSize() const;
        int getGlType();
        int getGlType() const;

		virtual void resize(unsigned int elementCount, bool copy=false);

    protected:
        RenderElement();
        virtual bool init(RenderElementType type, unsigned int elementSize, unsigned int componentCount, unsigned int componenetSize, int glType);
        
	private:
		RenderElementType	_elementType;
		std::string			_elementName;
        int                 _elementIndex;

		unsigned int		_elementCount;
		unsigned int		_elementSize;
        unsigned int        _elementCapacity;
		unsigned int		_componentCount;
		unsigned int		_componentSize;
		int					_glType;
		
	};
	
}}
#endif
#endif
