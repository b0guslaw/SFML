////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_VERTEXARRAY_HPP
#define SFML_VERTEXARRAY_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <vector>


namespace sf
{
////////////////////////////////////////////////////////////
/// \brief Define a set of one or more 2D primitives
///
////////////////////////////////////////////////////////////
class SFML_API VertexArray : public Drawable
{
public :

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    /// Creates an empty vertex array.
    ///
    ////////////////////////////////////////////////////////////
    VertexArray();

    ////////////////////////////////////////////////////////////
    /// \brief Construct the vertex array with a type and an initial number of vertices
    ///
    /// \param type        Type of primitives
    /// \param vertexCount Initial number of vertices in the array
    ///
    ////////////////////////////////////////////////////////////
    VertexArray(PrimitiveType type, unsigned int vertexCount = 0);

    ////////////////////////////////////////////////////////////
    /// \brief Return the vertices count
    ///
    /// \return Number of vertices in the array
    ///
    ////////////////////////////////////////////////////////////
    unsigned int GetVertexCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get a read-write access to a vertex by its index
    ///
    /// This function doesn't check \a index, it must be in range
    /// [0, GetVertexCount() - 1].
    ///
    /// \param index Index of the vertex to get
    ///
    /// \return Reference to the index-th vertex
    ///
    /// \see GetVertexCount
    ///
    ////////////////////////////////////////////////////////////
    Vertex& operator [](unsigned int index);

    ////////////////////////////////////////////////////////////
    /// \brief Get a read-only access to a vertex by its index
    ///
    /// This function doesn't check \a index, it must be in range
    /// [0, GetVertexCount() - 1].
    ///
    /// \param index Index of the vertex to get
    ///
    /// \return Const reference to the index-th vertex
    ///
    /// \see GetVertexCount
    ///
    ////////////////////////////////////////////////////////////
    const Vertex& operator [](unsigned int index) const;

    ////////////////////////////////////////////////////////////
    /// \brief Clear the vertex array
    ///
    /// This function removes all the vertices from the array.
    /// It doesn't deallocate the corresponding memory, so that
    /// adding new vertices after clearing doesn't involve
    /// reallocating all the memory.
    ///
    ////////////////////////////////////////////////////////////
    void Clear();

    ////////////////////////////////////////////////////////////
    /// \brief Resize the vertex array
    ///
    /// If \a count is greater than the current size, the previous
    /// vertices are kept and new (default-constructed) vertices are
    /// added.
    /// If \a count is less than the current size, existing vertices
    /// are removed from the array.
    ///
    /// \param vertexCount New size of the array (number of vertices)
    ///
    ////////////////////////////////////////////////////////////
    void Resize(unsigned int vertexCount);

    ////////////////////////////////////////////////////////////
    /// \brief Add a vertex to the array
    ///
    /// \param vertex Vertex to add
    ///
    ////////////////////////////////////////////////////////////
    void Append(const Vertex& vertex);

    ////////////////////////////////////////////////////////////
    /// \brief Set the type of primitives to draw
    ///
    /// This function defines how the vertices must be interpreted
    /// when it's time to draw them:
    /// \li As points
    /// \li As lines
    /// \li As triangles
    /// \li As quads
    /// The default primitive type is sf::Points.
    ///
    /// \param type Type of primitive
    ///
    ////////////////////////////////////////////////////////////
    void SetPrimitiveType(PrimitiveType type);

    ////////////////////////////////////////////////////////////
    /// \brief Get the type of primitives drawn by the vertex array
    ///
    /// \return Primitive type
    ///
    ////////////////////////////////////////////////////////////
    PrimitiveType GetPrimitiveType() const;

    ////////////////////////////////////////////////////////////
    /// \brief Compute the bounding rectangle of the vertex array
    ///
    /// This function returns the axis-aligned rectangle that
    /// contains all the vertices of the array.
    ///
    /// \return Bounding rectangle of the vertex array
    ///
    ////////////////////////////////////////////////////////////
    FloatRect GetBounds() const;

private :

    ////////////////////////////////////////////////////////////
    /// \brief Draw the vertex array to a render target
    ///
    /// \param target Render target to draw to
    /// \param states Current render states
    ///
    ////////////////////////////////////////////////////////////
    virtual void Draw(RenderTarget& target, RenderStates states) const;

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    std::vector<Vertex> myVertices;      ///< Vertices contained in the array
    PrimitiveType       myPrimitiveType; ///< Type of primitives to draw
};

} // namespace sf


#endif // SFML_VERTEXARRAY_HPP


////////////////////////////////////////////////////////////
/// \class sf::VertexArray
/// \ingroup graphics
///
/// sf::VertexArray is a very simple wrapper around a dynamic
/// array of vertices and a primitives type.
///
/// It inherits sf::Drawable, but unlike other drawables it
/// is not transformable.
///
/// Example:
/// \code
/// sf::VertexArray lines(sf::LinesStrip, 4);
/// lines[0].Position = sf::Vector2f(10, 0);
/// lines[1].Position = sf::Vector2f(20, 0);
/// lines[2].Position = sf::Vector2f(30, 5);
/// lines[3].Position = sf::Vector2f(40, 2);
///
/// window.Draw(lines);
/// \endcode
///
/// \see sf::Vertex
///
////////////////////////////////////////////////////////////