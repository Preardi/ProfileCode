#include "general_objects.h"
#include <iostream>
interpolators_objects::Mesh::~Mesh() = default;

const std::vector<geometry_objects::Point2D>* interpolators_objects::Mesh::getPoints() const
{
	const std::vector<geometry_objects::Point2D>* res = &p_data->verts;
	return res;
}

const std::vector<double>* interpolators_objects::Mesh::getValues() const
{
	const std::vector<double>* res = &p_data->vals ;
	return res;
}

interpolators_objects::Mesh::Mesh(const std::vector<geometry_objects::Point2D>&verts, const std::vector<double>&vals)
{
	p_data = std::make_unique<MeshPrivateData>();
	p_data->verts = verts;
	p_data->vals = vals;
}

interpolators_objects::Mesh::Mesh(const Mesh& m)
{
	p_data = std::make_unique<MeshPrivateData>(*m.p_data);
}

interpolators_objects::Mesh& interpolators_objects::Mesh::operator=(const Mesh& m)
{
	p_data = std::make_unique<MeshPrivateData>(*m.p_data);
	return *this;
}



void interpolators_objects::IInterpolator::setMesh(const interpolators_objects::Mesh* const mesh)
{
    p_mesh = mesh;
}

void interpolators_objects::IInterpolator::setValues(const std::vector<double>& values_)
{
    values = values_;
}



