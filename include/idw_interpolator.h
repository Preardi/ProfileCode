#pragma once
#include "general_objects.h"
class IDWInterpolator :public interpolators_objects::IInterpolator {
	public:
		IDWInterpolator() = default;
		virtual ~IDWInterpolator() = default;
		virtual std::vector<double> runInterpolation(const std::vector<geometry_objects::Point2D>& points) const override;
		void setRadius(double);
		void setPower(double);
	private:
		// радиус интерпол€ции
		double R = std::numeric_limits<double>::max();
		// степень 1/r
		double power = 2.;
		std::vector<int> findNearPoint(geometry_objects::Point2D&, const std::vector<geometry_objects::Point2D>*) const ;

};
