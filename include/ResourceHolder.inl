
template <typename Resource, typename Identifier>
void
ResourceHolder<Resource, Identifier>::load( Identifier id, const std::string& filename )
{
	// Cria e lê o recurso
	std::unique_ptr<Resource> resource( new Resource() );

	if ( !resource->loadFromFile( filename ) )
		throw std::runtime_error( "ResourceHolder::load - Falha ao ler " + filename );

	// Se ler com sucesso entao insira no map
	insertResource(id, std::move( resource ) ); // std::move eh necessario por conta do std::unique_ptr;
}


template <typename Resource, typename Identifier>
template <typename Parameter>
void
ResourceHolder<Resource, Identifier>::load( Identifier id, const std::string& filename, const Parameter& secondParam )
{
	// Cria e le um recurso
	std::unique_ptr<Resource> resource( new Resource() );

	// Lança um erro se nao conseguir ler
	if ( !resource->loadFromFile(filename, secondParam ) )
		throw std::runtime_error("ResourceHolder::load - Falha ao ler " + filename );

	// Se ser com sucesso insira no map
	insertResource( id, std::move( resource ) );
}	

template <typename Resource, typename Identifier>
Resource&
ResourceHolder<Resource, Identifier>::get( Identifier id )
{
	auto found = mResourceMap.find( id );
	assert( found != mResourceMap.end() );

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource&
ResourceHolder<Resource, Identifier>::get( Identifier id ) const
{
	auto found = mResourceMap.find( id );
	assert( found != mResourceMap.end() );

	return *found->second;
}

template <typename Resource, typename Identifier>
void
ResourceHolder<Resource, Identifier>::insertResource( Identifier id, std::unique_ptr<Resource> resource )
{
	// Insere e checa se foi inserido com sucesso.
	auto inserted = mResourceMap.insert( std::make_pair( id, std::move( resource ) ) );
	assert( inserted.second );
}
