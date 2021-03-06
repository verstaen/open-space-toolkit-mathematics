////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Mathematics
/// @file           OpenSpaceToolkit/Mathematics/Geometry/3D/Transformations/Rotations/RotationVector.test.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Transformations/Rotations/RotationVector.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Transformations/Rotations/Quaternion.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/Angle.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Constructor)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(45.0))) ;

        RotationVector rotationVector = { { 0.0, 0.0, 1.0 }, Angle::Degrees(45.0) } ;

        EXPECT_TRUE(rotationVector.isDefined()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector({ 0.0, 0.0, 0.9 }, Angle::Degrees(45.0))) ;
        EXPECT_ANY_THROW(RotationVector({ 0.0, 0.0, 1.1 }, Angle::Degrees(45.0))) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, EqualToOperator)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_TRUE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)) == RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0))) ;
        EXPECT_TRUE(RotationVector({ 0.0, 1.0, 0.0 }, Angle::Degrees(10.0)) == RotationVector({ 0.0, 1.0, 0.0 }, Angle::Degrees(10.0))) ;
        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(20.0)) == RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(20.0))) ;

        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(30.0)) == RotationVector({ 0.0, 0.0, +1.0 }, Angle::Degrees(+30.0))) ;
        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(30.0)) == RotationVector({ 0.0, 0.0, -1.0 }, Angle::Degrees(-30.0))) ;

        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) == RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+360.0))) ;
        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) == RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-360.0))) ;

        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+180.0)) == RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-180.0))) ;

    }

    {

        EXPECT_FALSE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)) == RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(1.0))) ;

    }

    {

        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) == RotationVector::Undefined()) ;
        EXPECT_FALSE(RotationVector::Undefined() == RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0))) ;
        EXPECT_FALSE(RotationVector::Undefined() == RotationVector::Undefined()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, NotEqualToOperator)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_TRUE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)) != RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(1.0))) ;

    }

    {

        EXPECT_TRUE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) != RotationVector::Undefined()) ;
        EXPECT_TRUE(RotationVector::Undefined() != RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0))) ;
        EXPECT_TRUE(RotationVector::Undefined() != RotationVector::Undefined()) ;

    }

    {

        EXPECT_FALSE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)) != RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0))) ;
        EXPECT_FALSE(RotationVector({ 0.0, 1.0, 0.0 }, Angle::Degrees(10.0)) != RotationVector({ 0.0, 1.0, 0.0 }, Angle::Degrees(10.0))) ;
        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(20.0)) != RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(20.0))) ;

        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(30.0)) != RotationVector({ 0.0, 0.0, +1.0 }, Angle::Degrees(+30.0))) ;
        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(30.0)) != RotationVector({ 0.0, 0.0, -1.0 }, Angle::Degrees(-30.0))) ;

        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) != RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+360.0))) ;
        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(0.0)) != RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-360.0))) ;

        EXPECT_FALSE(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+180.0)) != RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-180.0))) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, StreamOperator)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(10.0)) << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, IsDefined)
{

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_TRUE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(10.0)).isDefined()) ;

    }

    {

        EXPECT_FALSE(RotationVector::Undefined().isDefined()) ;
        EXPECT_FALSE(RotationVector(Vector3d::Undefined(), Angle::Degrees(10.0)).isDefined()) ;
        EXPECT_FALSE(RotationVector({ 1.0, 0.0, 0.0 }, Angle::Undefined()).isDefined()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, GetAxis)
{

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_EQ(Vector3d(1.0, 0.0, 0.0), RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(10.0)).getAxis()) ;
        EXPECT_EQ(Vector3d(0.0, 1.0, 0.0), RotationVector({ 0.0, 1.0, 0.0 }, Angle::Degrees(20.0)).getAxis()) ;
        EXPECT_EQ(Vector3d(0.0, 0.0, 1.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(30.0)).getAxis()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Undefined().getAxis()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, GetAngle)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_EQ(Angle::Degrees(0.0), RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)).getAngle()) ;

        EXPECT_EQ(Angle::Degrees(-30.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-30.0)).getAngle()) ;
        EXPECT_EQ(Angle::Degrees(+30.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+30.0)).getAngle()) ;

        EXPECT_EQ(Angle::Degrees(-90.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-90.0)).getAngle()) ;
        EXPECT_EQ(Angle::Degrees(+90.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+90.0)).getAngle()) ;

        EXPECT_EQ(Angle::Degrees(-180.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-180.0)).getAngle()) ;
        EXPECT_EQ(Angle::Degrees(+180.0), RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+180.0)).getAngle()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Undefined().getAngle()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, ToString)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_EQ("[1.0, 0.0, 0.0] : 0.0 [deg]", RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)).toString()) ;

        EXPECT_EQ("[0.0, 0.0, 1.0] : -30.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-30.0)).toString()) ;
        EXPECT_EQ("[0.0, 0.0, 1.0] : 30.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+30.0)).toString()) ;

        EXPECT_EQ("[0.0, 0.0, 1.0] : -90.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-90.0)).toString()) ;
        EXPECT_EQ("[0.0, 0.0, 1.0] : 90.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+90.0)).toString()) ;

        EXPECT_EQ("[0.0, 0.0, 1.0] : -180.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-180.0)).toString()) ;
        EXPECT_EQ("[0.0, 0.0, 1.0] : 180.0 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+180.0)).toString()) ;

    }

    {

        EXPECT_EQ("[1.000, 0.000, 0.000] : 0.000 [deg]", RotationVector({ 1.0, 0.0, 0.0 }, Angle::Degrees(0.0)).toString(3)) ;

        EXPECT_EQ("[0.000, 0.000, 1.000] : -30.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-30.0)).toString(3)) ;
        EXPECT_EQ("[0.000, 0.000, 1.000] : 30.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+30.0)).toString(3)) ;

        EXPECT_EQ("[0.000, 0.000, 1.000] : -90.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-90.0)).toString(3)) ;
        EXPECT_EQ("[0.000, 0.000, 1.000] : 90.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+90.0)).toString(3)) ;

        EXPECT_EQ("[0.000, 0.000, 1.000] : -180.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(-180.0)).toString(3)) ;
        EXPECT_EQ("[0.000, 0.000, 1.000] : 180.000 [deg]", RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(+180.0)).toString(3)) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Undefined().toString()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Undefined)
{

    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector::Undefined()) ;
        EXPECT_FALSE(RotationVector::Undefined().isDefined()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Unit)
{

    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector::Unit()) ;
        EXPECT_EQ(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Zero()), RotationVector::Unit()) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, X)
{

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector::X(Angle::Degrees(45.0))) ;

        const RotationVector rotationVector = RotationVector::X(Angle::Degrees(45.0)) ;

        EXPECT_EQ(Vector3d::X(), rotationVector.getAxis()) ;
        EXPECT_EQ(Angle::Degrees(45.0), rotationVector.getAngle()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::X(Angle::Undefined())) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Y)
{

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector::Y(Angle::Degrees(45.0))) ;

        const RotationVector rotationVector = RotationVector::Y(Angle::Degrees(45.0)) ;

        EXPECT_EQ(Vector3d::Y(), rotationVector.getAxis()) ;
        EXPECT_EQ(Angle::Degrees(45.0), rotationVector.getAngle()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Y(Angle::Undefined())) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Z)
{

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_NO_THROW(RotationVector::Z(Angle::Degrees(45.0))) ;

        const RotationVector rotationVector = RotationVector::Z(Angle::Degrees(45.0)) ;

        EXPECT_EQ(Vector3d::Z(), rotationVector.getAxis()) ;
        EXPECT_EQ(Angle::Degrees(45.0), rotationVector.getAngle()) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Z(Angle::Undefined())) ;

    }

}

TEST (OpenSpaceToolkit_Mathematics_Geometry_3D_Transformations_Rotations_RotationVector, Quaternion)
{

    using ostk::core::types::Real ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::trf::rot::Quaternion ;
    using ostk::math::geom::d3::trf::rot::RotationVector ;

    {

        EXPECT_EQ(RotationVector::Unit(), RotationVector::Quaternion(Quaternion::Unit())) ;

        EXPECT_EQ(RotationVector({ 0.0, 0.0, 1.0 }, Angle::Degrees(180.0)), RotationVector::Quaternion(Quaternion::XYZS(0.0, 0.0, 1.0, 0.0))) ;

    }

    {

        EXPECT_ANY_THROW(RotationVector::Quaternion(Quaternion::Undefined())) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
