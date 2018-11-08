#ifndef __GRAPH__HXX__
#define __GRAPH__HXX__

#include <algorithm>
#include <limits>
#include <deque>
#include <queue>
#include <iostream>

// -------------------------------------------------------------------------
template< class T, class C >
Graph< T, C >::
Graph( )
{
  this->m_Vertices.clear( );
  this->m_Costs.clear( );
}

// -------------------------------------------------------------------------
template< class T, class C >
Graph< T, C >::
~Graph( )
{
}

// -------------------------------------------------------------------------
template< class T, class C >
unsigned long Graph< T, C >::
AddVertex( const T& v )
{
  this->m_Vertices.push_back( v );
  return( this->m_Vertices.size( ) - 1 );
}

// -------------------------------------------------------------------------
template< class T, class C >
void Graph< T, C >::
SetArc( unsigned long i, unsigned long j, const C& c )
{
  this->m_Costs[ i ][ j ] = c;
}

// -------------------------------------------------------------------------
template< class T, class C >
unsigned long Graph< T, C >::
GetNumberOfVertices( ) const
{
  return( this->m_Vertices.size( ) );
}

// -------------------------------------------------------------------------
template< class T, class C >
const T& Graph< T, C >::
GetVertex( unsigned long i ) const
{
  return( this->m_Vertices[ i ] );
}

// -------------------------------------------------------------------------
template< class T, class C >
bool Graph< T, C >::
HasArc( unsigned long i, unsigned long j ) const
{
  typename TMatrix::const_iterator rIt = this->m_Costs.find( i );
  if( rIt != this->m_Costs.end( ) )
    return( rIt->second.find( j ) != rIt->second.end( ) );
  return( false );
}

// -------------------------------------------------------------------------
template< class T, class C >
const C& Graph< T, C >::
GetCost( unsigned long i, unsigned long j ) const
{
  return( this->m_Costs[ i ][ j ] );
}

// -------------------------------------------------------------------------
template< class T, class C >
void Graph< T, C >::
PrintPlaneGraph( ) const
{
  typename TVertices::const_iterator vIt = this->m_Vertices.begin( );
  for( ; vIt != this->m_Vertices.end( ); vIt++ )
    std::cout << *vIt << " : ";
  std::cout << std::endl;
}

// -------------------------------------------------------------------------
template< class T, class C >
void Graph< T, C >::
PrintPreorderGraph( unsigned long i ) const
{
  std::vector< bool > m( this->m_Vertices.size( ), false );
  this->PrintPreorderGraph( i, m );
  std::cout << std::endl;
}

// -------------------------------------------------------------------------
template< class T, class C >
void Graph< T, C >::
PrintPreorderGraph( unsigned long i, std::vector< bool >& m )
{
  if( m[ i ] )
    return;

  m[ i ] = true;
  std::cout << this->m_Vertices[ i ] << " : ";

  typename TMatrix::const_iterator rIt = this->m_Costs.find( i );
  if( rIt != this->m_Costs.end( ) )
  {
    typename TRow::const_iterator cIt = rIt->second.begin( );
    for( ; cIt != rIt->second.end( ); cIt++ )
      this->PrintPreorderGraph( cIt->first, m );

  } // fi
}

// -------------------------------------------------------------------------
template< class T, class C >
void Graph< T, C >::
PrintLevelsGraph( unsigned long i ) const
{
  std::queue< unsigned long > q;
  std::vector< bool > m( this->m_Vertices.size( ), false );

  q.push( i );
  while( !q.empty( ) )
  {
    unsigned long n = q.front( );
    q.pop( );

    // check if n has been visited
    if( m[ n ] )
      continue;

    // Mark it as visited
    m[ n ] = true;

    // Print it
    std::cout << this->m_Vertices[ n ] << " : ";

    // Iterate over neighbors
    typename TMatrix::const_iterator rIt = this->m_Costs.find( n );
    if( rIt != this->m_Costs.end( ) )
    {
      typename TRow::const_iterator cIt = rIt->second.begin( );
      for( ; cIt != rIt->second.end( ); cIt++ )
        q.push( cIt->first );

    } // fi

  } // elihw

  std::cout << std::endl;
}

// -------------------------------------------------------------------------
template< class T, class C >
typename Graph< T, C >::
TTree Graph< T, C >::
Dijkstra( unsigned long s ) const
{
  TTree tree;
  std::deque< AuxDijkstraNode > q;
  std::vector< bool > m( this->m_Vertices.size( ), false );

  AuxDijkstraNode n;
  n.Node = s;
  n.Parent = s;
  n.Cost = C( 0 );
  q.push_back( n );

  while( !q.empty( ) )
  {
    n = q.front( );
    std::pop_heap( q.begin( ), q.end( ) );
    q.pop_back( );

    // check if n has been visited
    if( m[ n.Node ] )
      continue;

    // Mark it as visited
    m[ n.Node ] = true;

    // Update tree
    tree[ n.Node ] = n.Parent;

    // Iterate over neighbors
    typename TMatrix::const_iterator rIt = this->m_Costs.find( n.Node );
    if( rIt != this->m_Costs.end( ) )
    {
      typename TRow::const_iterator cIt = rIt->second.begin( );
      for( ; cIt != rIt->second.end( ); cIt++ )
      {
        AuxDijkstraNode nn;
        nn.Node = cIt->first;
        nn.Parent = n.Node;
        nn.Cost = n.Cost + cIt->second;

        q.push_back( nn );
        std::push_heap( q.begin( ), q.end( ) );

      } // rof

    } // fi

  } // elihw

  return( tree );
}

// -------------------------------------------------------------------------
template < class T, class C >
Graph< T ,C > Graph < T, C >::Warshall( ) const
{
    Graph< T,C > warshall = *this;
    C infCost = std::numeric_limits< C >::max();

    unsigned long N = this->GetNumberOfVertices();
    for(unsigned int k=0 ; k<N ; k++)
    {
        for(unsigned int i=0 ; i<N ; i++)
        {
            for(unsigned int j=0 ; j<N ; j++)
            {
                    C dik = (warshall.HasArc(i,k))? warshall.GetCost(i,k): infCost;
                    C dkj = (warshall.HasArc(k,j))? warshall.GetCost(k,j): infCost;
                    C sum =
                        (dik != infCost && dkj != infCost )?
                        (dik + dkj): infCost;
                        C dij = (warshall.HasArc(i,j)) ? warshall.GetCost(i,j) : infCost;
                        C minVal = (dij < sum)? dij: sum;

                        if(minVal != infCost)
                         warshall.SetArc(i,j,minVal);
            }//for
        }//for
    }//for

    return(warshall);
}

// -------------------------------------------------------------------------
template< class T, class C >
bool Graph< T, C >::
IsBicolorable( ) const
{
  bool bicolorable = true;

  if( this->m_Vertices.size( ) > 0 )
  {
    static const unsigned char FIRST_COLOR = 0;
    static const unsigned char NO_COLOR = 3;

    std::queue< AuxDijkstraNode > q;
    std::vector< unsigned char > m( this->m_Vertices.size( ), NO_COLOR );

    for(
      unsigned long i = 0; i < this->m_Vertices.size( ) && bicolorable; i++
      )
    {
      if( m[ i ] != NO_COLOR )
        continue;

      AuxDijkstraNode n;
      n.Node = i;
      n.Parent = i;
      q.push( n );

      while( !q.empty( ) && bicolorable )
      {
        n = q.front( );
        q.pop( );

        // check if n has been visited
        if( m[ n.Node ] != NO_COLOR )
          continue;

        // Mark it as visited
        if( n.Node == n.Parent )
          m[ n.Node ] = FIRST_COLOR;
        else
          m[ n.Node ] = ( m[ n.Parent ] + 1 ) % 2;

        // Iterate over neighbors
        typename TMatrix::const_iterator rIt = this->m_Costs.find( n.Node );
        if( rIt != this->m_Costs.end( ) )
        {
          typename TRow::const_iterator cIt = rIt->second.begin( );
          for( ; cIt != rIt->second.end( ) && bicolorable; cIt++ )
          {
            if( m[ cIt->first ] == NO_COLOR )
            {
              AuxDijkstraNode nn;
              nn.Node = cIt->first;
              nn.Parent = n.Node;
              q.push( nn );
            }
            else
              bicolorable = ( m[ cIt->first ] != m[ n.Node ] );

          } // rof

        } // fi

      } // elihw

    } // rof

  } // fi
  return( bicolorable );
}

#endif // __GRAPH__HXX__

// eof - Graph.hxx

