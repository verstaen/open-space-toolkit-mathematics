////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library ▸ Mathematics
/// @file           LibraryMathematicsPy/Geometry.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <LibraryMathematicsPy/Geometry/3D.cpp>
#include <LibraryMathematicsPy/Geometry/2D.cpp>
#include <LibraryMathematicsPy/Geometry/Angle.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     LibraryMathematicsPy_Geometry               ( )
{

    boost::python::object module(boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("Library.Mathematics.Geometry")))) ;

    boost::python::scope().attr("Geometry") = module ;

    boost::python::scope scope = module ;

    LibraryMathematicsPy_Geometry_Angle() ;
    LibraryMathematicsPy_Geometry_2D() ;
    LibraryMathematicsPy_Geometry_3D() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
