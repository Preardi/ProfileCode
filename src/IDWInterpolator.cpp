#include "IDWInterpolator.h"
std::vector<int> IDWInterpolator::findNearPoint( geometry_objects::Point2D& p0, const std::vector<geometry_objects::Point2D>* points) const {
	std::vector<int> resIds;
	int N = points->size();
	int i = 0;
	for (const auto& p : *points) {
		auto d = p0 - p;
		if (d.length() < R)
			resIds.push_back(i++);
	}
	return resIds;
}

std::vector<double> IDWInterpolator::runInterpolation(const std::vector<geometry_objects::Point2D>& points) const
{
	size_t nPts = points.size();
	std::vector<double> interpolateValues(nPts);
	std::vector<double> result_vals;
	const auto ref_pts = *p_mesh->getPoints();
	const auto ref_vals = *p_mesh->getValues();
	for (auto it = points.begin(); it != points.end();it++) {
		int id = it - points.begin();
		auto p0 = *it;
		const double& z = interpolateValues[id];
		std::vector<int> idsNeigPts = findNearPoint(p0, &ref_pts);
		double v = 0;
		for (int i : idsNeigPts) {
			const auto p = ref_pts[i];
			double dr = (p - p0).length();
			
			double multi = dr>0 ? 1 / pow(dr, power):0;
			v += ref_vals[i] * multi;
		}	
		result_vals.push_back(v);
	}
	return result_vals;
}

void IDWInterpolator::setRadius(double r_)
{
	R = r_;
}

void IDWInterpolator::setPower(double p_)
{
	power = p_;
}


