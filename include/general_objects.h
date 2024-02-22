#pragma once
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <memory>

namespace geometry_objects {
	struct Point2D {
		double x, y;
		Point2D() = default;
		Point2D(double x_, double y_)  {
            this->x = x_;
            this->y = y_;
        };

        //inline double& operator[](int i){ if (i){ if (i == 1){ return y; }; return z; }; return x; }
        //inline Point2D& operator=(const Point2D& rval) { x = rval.x; y = rval.y; return *this; }
        inline Point2D& operator+=(const Point2D& rval) { x += rval.x; y += rval.y; return *this; }
        inline friend Point2D operator+(Point2D lval, const Point2D& rval) { lval += rval; return lval; }
        inline Point2D& operator-=(const Point2D& rval) { x -= rval.x; y -= rval.y; return *this; }
        inline friend Point2D operator-(Point2D lval, const Point2D& rval) { lval -= rval; return lval; }
        inline double operator*(const Point2D& rval) { return x * rval.x + y * rval.y; }
        inline friend double operator*(const Point2D& lval, const Point2D& rval) { return lval.x * rval.x + lval.y * rval.y; }
        inline Point2D& operator*=(const double val) { x *= val; y *= val; return *this; }
        inline Point2D& operator/=(const double val) { *this *= 1. / val; return *this; }
        inline friend Point2D operator*(Point2D lval, const double val) { lval *= val; return lval; }
        inline friend Point2D operator*(const double val, Point2D rval) { return rval * val; }
        inline friend Point2D operator/(Point2D lval, const double val) { lval /= val; return lval; }
        inline friend Point2D operator/(const double val, Point2D rval) { return { val / rval.x, val / rval.y }; }
        inline friend double vecProd(const Point2D& l, const Point2D& r) { return l.x * r.y - r.x * l.y; }
        inline double sqrlength() const { return (x * x + y * y); }
        inline double length() const { return sqrt(x * x + y * y); }
        bool operator!=(const Point2D& p2) const { return (x != p2.x || y != p2.y); }
        bool operator==(const Point2D& p2) const { return (x == p2.x && y == p2.y); }
        inline Point2D operator-() const { return { -x, -y }; }
        // равенство двух точек
        inline bool is_close(const Point2D& p2, double eps) const { return (fabs(x - p2.x) < eps && fabs(y - p2.y) < eps); }
        // нормировка вектора
        inline void normalize() {
            double norm = 1. / length();
            x *= norm;
            y *= norm;
        }
	};
}

struct MeshPrivateData {
    // —писок координат узлов дл€ интерпол€ции
    std::vector<geometry_objects::Point2D> verts;
    // —писок значений в узлах 
    std::vector<double> vals;
};

namespace interpolators_objects {
	class Mesh {
	public:
		Mesh() = delete;
		Mesh(const std::vector<geometry_objects::Point2D>& verts, const std::vector<double>& vals);
		Mesh(const Mesh& m);
		Mesh& operator=(const Mesh& m);
		~Mesh();
        const std::vector<geometry_objects::Point2D>* getPoints() const;
        const std::vector<double>* getValues() const;
    private:
        std::unique_ptr<MeshPrivateData> p_data;
	};

    class IInterpolator {
    public:
        IInterpolator() = default;
        virtual ~IInterpolator() = default;
        virtual std::vector<double> runInterpolation(const std::vector<geometry_objects::Point2D>&points) const = 0;
        void setMesh(const interpolators_objects::Mesh* const mesh);
        void setValues(const std::vector<double>& values_);
        
    protected:
        // интерпол€ционна€ сетка
        const interpolators_objects::Mesh* p_mesh = nullptr;
        // значени€ на сетке (в €чейках или узлах)
        std::vector<double> values;
    };

}

