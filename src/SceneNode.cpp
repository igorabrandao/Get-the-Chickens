#include "SceneNode.h"
#include "Foreach.h"

#include <algorithm>
#include <cassert>

// Constructor
SceneNode::SceneNode()
: mChildren()
, mParent( nullptr )
{
}

void
SceneNode::attachChild( Ptr child )
{
	// A crianca mParent rebebe este scene node.
	child->mParent = this;
	// Inclui a crianca no vetor de criancas ( std::move eh necessario por conta do unique_ptr )
	mChildren.push_back( std::move( child ) );
}

SceneNode::Ptr
SceneNode::detachChild( const SceneNode& node )
{
	auto found = std::find_if( mChildren.begin(), mChildren.end(), [&] ( Ptr& p ) { return p.get() == &node; });
	assert( found != mChildren.end() );

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase( found );
	return result;
}

void
SceneNode::update( sf::Time dt )
{
	updateCurrent( dt );
	updateChildren( dt );
}

void
SceneNode::updateCurrent( sf::Time dt )
{
	/* Empty */
}

void
SceneNode::updateChildren( sf::Time dt )
{
	FOREACH( Ptr& child, mChildren )
		child->update( dt );
}

void
SceneNode::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	// Aplica a tranformacao ao no atual
	states.transform *= getTransform();

	// Desenha o noh e as criancas desse noh com as mudancas do transform
	drawCurrent( target, states );
	drawChildren( target, states );
}

void
SceneNode::drawCurrent( sf::RenderTarget& target, sf::RenderStates states ) const
{
	// Do nothing by default	
}

void
SceneNode::drawChildren( sf::RenderTarget& target, sf::RenderStates states ) const
{
	FOREACH( const Ptr& child, mChildren )
		child->draw( target, states );
}

sf::Vector2f
SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform
SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;

	for ( const SceneNode* node = this; node != nullptr; node = node->mParent )
		transform = node->getTransform() * transform;

	return transform;
}