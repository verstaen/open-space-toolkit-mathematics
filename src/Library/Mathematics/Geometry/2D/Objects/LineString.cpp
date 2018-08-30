////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/2D/Objects/LineString.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/2D/Objects/LineString.hpp>
#include <Library/Mathematics/Geometry/2D/Objects/Segment.hpp>

#include <Library/Core/Error.hpp>
#include <Library/Core/Utilities.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d2
{
namespace objects
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                LineString::LineString                      (   const   Array<Point>&               aPointArray                                 )
                                :   Object(),
                                    points_(aPointArray)
{
    
}

LineString*                     LineString::clone                           ( ) const
{
    return new LineString(*this) ;
}

bool                            LineString::operator ==                     (   const   LineString&                 aLineString                                 ) const
{
    return points_ == aLineString.points_ ;
}

bool                            LineString::operator !=                     (   const   LineString&                 aLineString                                 ) const
{
    return !((*this) == aLineString) ;
}

bool                            LineString::isDefined                       ( ) const
{
    return !points_.isEmpty() ;
}

bool                            LineString::isEmpty                         ( ) const
{
    return points_.isEmpty() ;
}

bool                            LineString::isNear                          (   const   LineString&                 aLineString,
                                                                                const   Real&                       aTolerance                                  ) const
{

    if ((this->isEmpty()) || (aLineString.isEmpty()))
    {
        return false ;
    }

    if (points_.getSize() != aLineString.points_.getSize())
    {
        return false ;
    }

    for (auto pointTuple : library::core::ctnr::iterators::Zip(points_, aLineString.points_))
    {

        if (!std::get<0>(pointTuple).isNear(std::get<1>(pointTuple), aTolerance))
        {
            return false ;
        }

    }

    return true ;
    
}

Size                            LineString::getPointCount                   ( ) const
{
    return points_.getSize() ;
}

Point                           LineString::getPointClosestTo               (   const   Point&                      aPoint                                      ) const
{

    if (!aPoint.isDefined())
    {
        throw library::core::error::runtime::Undefined("Point") ;
    }

    if (this->isEmpty())
    {
        throw library::core::error::runtime::Undefined("Point set") ;
    }

    Point const* pointPtr = nullptr ;
    Real minDistance = Real::Undefined() ;

    for (const auto& point : points_)
    {

        const Real distance = (point - aPoint).squaredNorm() ;

        if ((!minDistance.isDefined()) || (distance < minDistance))
        {

            pointPtr = &point ;

            minDistance = distance ;

        }

    }

    return *pointPtr ;

}

String                          LineString::toString                        (   const   Object::Format&             aFormat,
                                                                                const   Integer&                    aPrecision                                  ) const
{

    switch (aFormat)
    {

        case Object::Format::Standard:
        {

            String pointSetString = "[" ;

            Index pointIndex = 0 ;
            const Size pointCount = this->getPointCount() ;

            for (const auto& point : points_)
            {

                pointSetString += point.toString(Object::Format::Standard, aPrecision) ;

                if ((pointIndex + 1) < pointCount)
                {
                    pointSetString += " -> " ;
                }

                pointIndex++ ;

            }

            pointSetString += "]" ;

            return pointSetString ;

        }

        case Object::Format::WKT:
        {

            String pointSetString = "LINESTRING(" ;

            Index pointIndex = 0 ;
            const Size pointCount = this->getPointCount() ;

            for (const auto& point : points_)
            {

                pointSetString += String::Format("{} {}", Real(point.x()).toString(aPrecision), Real(point.y()).toString(aPrecision)) ;

                if ((pointIndex + 1) < pointCount)
                {
                    pointSetString += ", " ;
                }

                pointIndex++ ;

            }

            pointSetString += ")" ;

            return pointSetString ;

        }

        default:
            throw library::core::error::runtime::Wrong("Format") ;
            break ;

    }

    return String::Empty() ;
   
}

void                            LineString::print                           (           std::ostream&               anOutputStream,
                                                                                        bool                        displayDecorators                           ) const
{

    displayDecorators ? library::core::utils::Print::Header(anOutputStream, "Point Set") : void () ;

    for (const auto& point : points_)
    {
        library::core::utils::Print::Line(anOutputStream)                       << (point.isDefined() ? point.toString() : "Undefined") ;
    }

    displayDecorators ? library::core::utils::Print::Footer(anOutputStream) : void () ;

}

LineString::ConstIterator       LineString::begin                           ( ) const
{
    return points_.begin() ;
}

LineString::ConstIterator       LineString::end                             ( ) const
{
    return points_.end() ;
}

void                            LineString::translate                       (   const   Vector2d&                   aTranslation                                )
{

    if (!aTranslation.isDefined())
    {
        throw library::core::error::runtime::Undefined("Translation") ;
    }

    if (!this->isDefined())
    {
        throw library::core::error::runtime::Undefined("LineString") ;
    }

    for (auto& point : points_)
    {
        point.translate(aTranslation) ;
    }

}

LineString                      LineString::Empty                           ( )
{
    return { Array<Point>::Empty() } ;
}

LineString                      LineString::Segment                         (   const   objects::Segment&           aSegment                                    )
{

    if (!aSegment.isDefined())
    {
        throw library::core::error::runtime::Undefined("Segment") ;
    }

    return { { aSegment.getFirstPoint(), aSegment.getSecondPoint() } } ;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////