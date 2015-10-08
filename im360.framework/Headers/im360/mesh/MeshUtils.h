/*
 *  MeshUtils.h
 *  player
 *
 *  Created by Ben Siroshton on 8/6/10.
 *  Copyright 2010 Immersive Ventures. All rights reserved.
 *
 */

#ifndef _MeshUtils_h_
#define _MeshUtils_h_

#include "MeshData.h"
#include "VertexBuffer3.h"
#include "VertexBuffer2.h"
#include "IndexBuffer.h"
#include "UVBuffer.h"
#include "im360/math/Bounds3.h"

#ifdef __cplusplus
// -----------------------------------------------------------------------
// C++ Interface
// -----------------------------------------------------------------------
namespace im360 {
namespace mesh {

    I3DAPI im360::mesh::MeshData::pointer createSphere(float radius, unsigned int slices, unsigned int stacks, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);
    I3DAPI void createSphere(im360::mesh::VertexBuffer3 * vertexBuffer, im360::mesh::IndexBuffer * indexBuffer, im360::mesh::UVBuffer * uvBuffer, float radius, unsigned int slices, unsigned int stacks, float u1=0.f, float v1=0.f, float u2=1.f, float v2=1.f);

    I3DAPI im360::mesh::MeshData::pointer createPlane3(float width=1.0f, float height=1.0f);
    I3DAPI void createPlane3(im360::mesh::VertexBuffer3 * vertexBuffer, im360::mesh::IndexBuffer * indexBuffer, im360::mesh::UVBuffer * uvBuffer, float width=1.0f, float height=1.0f);

    I3DAPI im360::mesh::MeshData::pointer createPlane2(float width=1.0f, float height=1.0f);
    I3DAPI void createPlane2(im360::mesh::VertexBuffer2 * vertexBuffer, im360::mesh::IndexBuffer * indexBuffer, im360::mesh::UVBuffer * uvBuffer, float width=1.0f, float height=1.0f);

    I3DAPI im360::mesh::MeshData::pointer createCube(float radius, int cols, int rows, std::string order);

    im360::math::Bounds3 calculateBounds(im360::mesh::MeshData::pointer mesh);

}}
#endif
#endif
