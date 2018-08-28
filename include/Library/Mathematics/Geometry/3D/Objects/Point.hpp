////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Objects/Point.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_3D_Objects_Point__
#define __Library_Mathematics_Geometry_3D_Objects_Point__

#include <Library/Mathematics/Geometry/3D/Object.hpp>
#include <Library/Mathematics/Objects/Vector.hpp>

#include <Library/Core/Types/Real.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d3
{
namespace objects
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Real ;

using library::math::obj::Vector3d ;
using library::math::geom::d3::Object ;
using library::math::geom::trf::rot::Quaternion ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Point
///
/// @ref                        https://en.wikipedia.org/wiki/Point_(geometry)

class Point : public Object, public Vector3d
{

    public:

        /// @brief              Constructor
        ///
        /// @code
        ///                     Point point(0.0, 0.0, 0.0) ;
        /// @endcode
        ///
        /// @param              [in] aFirstCoordinate A first coordinate
        /// @param              [in] aSecondCoordinate A second coordinate
        /// @param              [in] aThirdCoordinate A third coordinate

                                Point                                       (   const   Real&                       aFirstCoordinate,
                                                                                const   Real&                       aSecondCoordinate,
                                                                                const   Real&                       aThirdCoordinate                            ) ;

        /// @brief              Constructor
        ///
        /// @code
        ///                     Point point({ 0.0, 0.0, 0.0 }) ;
        /// @endcode
        ///
        /// @param              [in] aVector A position vector

                                Point                                       (   const   Vector3d&                   aVector                                     ) ;

        /// @brief              Clone point
        ///
        /// @return             Pointer to cloned point

        virtual Point*          clone                                       ( ) const override ;

        /// @brief              Equal to operator
        ///
        /// @param              [in] aPoint A point
        /// @return             True if points are equal

        bool                    operator ==                                 (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Not equal to operator
        ///
        /// @param              [in] aPoint A point
        /// @return             True if points not are equal

        bool                    operator !=                                 (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Addition operator: translate point along vector
        ///
        /// @code
        ///                     Point(0.0, 0.0, 0.0) + Vector3d(0.0, 0.0, 1.0) ; // [0.0, 0.0, 1.0]
        /// @encode
        ///
        /// @param              [in] aVector A translation vector
        /// @return             A point

        Point                   operator +                                  (   const   Vector3d&                   aVector                                     ) const ;

        /// @brief              Subtraction operator: translate point along opposite vector
        ///
        /// @code
        ///                     Point(0.0, 0.0, 1.0) - Vector3d(0.0, 0.0, 1.0) ; // [0.0, 0.0, 0.0]
        /// @encode
        ///
        /// @param              [in] aVector A translation vector
        /// @return             A point

        Point                   operator -                                  (   const   Vector3d&                   aVector                                     ) const ;

        /// @brief              Subtraction operator: get translation vector between two points
        ///
        /// @code
        ///                     Point(0.0, 0.0, 1.0) - Point(0.0, 0.0, 0.0)  ; // [0.0, 0.0, 1.0]
        /// @encode
        ///
        /// @param              [in] aPoint A point
        /// @return             A translation vector

        Vector3d                operator -                                  (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Output stream operator
        ///
        /// @code
        ///                     std::cout << Point(0.0, 0.0, 0.0) ;
        /// @endcode
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] aPoint A point
        /// @return             An output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Point&                      aPoint                                      ) ;

        /// @brief              Check if point is defined
        ///
        /// @code
        ///                     Point(0.0, 0.0, 0.0).isDefined() ; // True
        /// @endcode
        ///
        /// @return             True if point is defined

        virtual bool            isDefined                                   ( ) const override ;

        /// @brief              Check if point is near another point
        ///
        /// @code
        ///                     Point(0.0, 0.0, 0.0).isNear(Point(0.0, 0.0, 0.0), 1e-15) ; // True
        /// @endcode
        ///
        /// @param              [in] aPoint A point
        /// @param              [in] aTolerance A tolerance
        /// @return             True if point is near another point

        bool                    isNear                                      (   const   Point&                      aPoint,
                                                                                const   Real&                       aTolerance                                  ) const ;

        /// @brief              Translate point
        ///
        /// @param              [in] aTranslation A translation vector

        virtual void            translate                                   (   const   Vector3d&                   aTranslation                                ) override ;

        /// @brief              Rotate point
        ///
        /// @param              [in] aRotation A rotation quaternion
        
        virtual void            rotate                                      (   const   Quaternion&                 aRotation                                   ) override ;

        /// @brief              Constructs an undefined point
        ///
        /// @code
        ///                     Point point = Point::Undefined() ; // Undefined
        /// @endcode
        ///
        /// @return             Undefined point

        static Point            Undefined                                   ( ) ;

        /// @brief              Constructs a point at origin
        ///
        /// @code
        ///                     Point point = Point::Origin() ; // [0.0, 0.0, 0.0]
        /// @endcode
        ///
        /// @return             Point at origin

        static Point            Origin                                      ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////