#include "student_code.h"
#include "mutablePriorityQueue.h"

using namespace std;

namespace CGL
{
  void BezierCurve::evaluateStep()
  {
    // TODO Part 1.
    // Perform one step of the Bezier curve's evaluation at t using de Casteljau's algorithm for subdivision.
    // Store all of the intermediate control points into the 2D vector evaluatedLevels.
      int level = evaluatedLevels.size();
      if (level >= numControlPoints)
          return;
      std::vector<Vector2D> newControlPoints; Vector2D newPoint = Vector2D();
      std::vector<Vector2D> &controlPoints = evaluatedLevels[level - 1];
      for (int i = 0; i < controlPoints.size()-1; i++) {
          newPoint = Vector2D(lerp(controlPoints[i].x, controlPoints[i + 1].x, t), lerp(controlPoints[i].y, controlPoints[i + 1].y, t));
          newControlPoints.push_back(newPoint);
      }
      evaluatedLevels.push_back(newControlPoints);
      return;
  }
    float BezierCurve::lerp(float a, float b, float t)
    {
        return (1 - t) * a + t * b;
    }
  Vector3D BezierPatch::evaluate(double u, double v) const
  {
    // TODO Part 2.
    // Evaluate the Bezier surface at parameters (u, v) through 2D de Casteljau subdivision.
    // (i.e. Unlike Part 1 where we performed one subdivision level per call to evaluateStep, this function
    // should apply de Casteljau's algorithm until it computes the final, evaluated point on the surface)
      std::vector<Vector3D> cntrlpoints2D;
      
      for (int i = 0; i < controlPoints.size(); i++) {
          cntrlpoints2D.push_back(evaluate1D(controlPoints[i], u));
      }
      return evaluate1D(cntrlpoints2D, v);
  }

  Vector3D BezierPatch::evaluate1D(std::vector<Vector3D> points, double t) const
  {
    // TODO Part 2.
    // Optional helper function that you might find useful to implement as an abstraction when implementing BezierPatch::evaluate.
    // Given an array of 4 points that lie on a single curve, evaluates the Bezier curve at parameter t using 1D de Casteljau subdivision.
      float x = 0; float y = 0; float z = 0;
      std::vector < std::vector<Vector3D> > levels;
      levels.push_back(points);
      std::vector<Vector3D> newControlPoints;
      Vector3D newPoint;
      
      for (int i = 0; i < 3; i++) {
          for (int j = 0; j < levels[i].size() - 1; j++) {
              
              x = lerp(levels[i][j].x, levels[i][j + 1].x, t);
              y = lerp(levels[i][j].y, levels[i][j + 1].y, t);
              z = lerp(levels[i][j].z, levels[i][j + 1].z, t);
              
              newPoint = Vector3D(x, y, z);
              newControlPoints.push_back(newPoint);
          }
          levels.push_back(newControlPoints);
          newControlPoints.clear();
      }
    return levels[3][0];
 }
    float BezierPatch::lerp(float a, float b, float t) const
    {
        return (1 - t) * a + t * b;
    }



  Vector3D Vertex::normal( void ) const
  {
    // TODO Part 3.
    // TODO Returns an approximate unit normal at this vertex, computed by
    // TODO taking the area-weighted average of the normals of neighboring
    // TODO triangles, then normalizing.
      Vector3D n(0,0,0); // initialize a vector to store your normal sum
      HalfedgeCIter h = halfedge(); // Since we're in a Vertex, this returns a halfedge pointing _away_ from that vertex
      h = h->twin(); // Bump over to the halfedge pointing _toward_ the vertex.
      // Now h->next() will be another edge on the same face, sharing the central vertex.
      HalfedgeCIter h_orig = h;
      do {
          Vector3D vect1 = h->vertex()->position - position;
          h = h->next()->twin();
          Vector3D vect2 = position - h->vertex()->position;
          n += cross(vect1, vect2);
      } while (h != h_orig);
    return n.unit();
  }

  EdgeIter HalfedgeMesh::flipEdge( EdgeIter e0 )
  {
    // TODO Part 4.
    // TODO This method should flip the given edge and return an iterator to the flipped edge.
      if (e0->isBoundary())
          return e0;
      
      //COLLECT ELEMENTS
      //half edges
      HalfedgeIter h0 = e0->halfedge();
      HalfedgeIter h1 = h0->next();
      HalfedgeIter h2 = h1->next();
      HalfedgeIter h3 = h0->twin();
      HalfedgeIter h4 = h3->next();
      HalfedgeIter h5 = h4->next();
      HalfedgeIter h6 = h1->twin();
      HalfedgeIter h7 = h2->twin();
      HalfedgeIter h8 = h4->twin();
      HalfedgeIter h9 = h5->twin();
      
      //vertices
      VertexIter v0 = h0->vertex();
      VertexIter v1 = h3->vertex();
      VertexIter v2 = h2->vertex();
      VertexIter v3 = h5->vertex();
      
      //edges
      EdgeIter e1 = h1->edge();
      EdgeIter e2 = h2->edge();
      EdgeIter e3 = h4->edge();
      EdgeIter e4 = h5->edge();
      
      //faces
      FaceIter f0 = h0->face();
      FaceIter f1 = h3->face();
      
      //REASSIGN ELEMENTS
      //halfedges
      h0->setNeighbors(h1, h3, v3, e0, f0);
      h1->setNeighbors(h2, h7, v2, e2, f0);
      h2->setNeighbors(h0, h8, v0, e3, f0);
      h3->setNeighbors(h4, h0, v2, e0, f1);
      h4->setNeighbors(h5, h9, v3, e4, f1);
      h5->setNeighbors(h3, h6, v1, e1, f1);
      h6->setNeighbors(h6->next(), h5, v2, e1, h6->face());
      h7->setNeighbors(h7->next(), h1, v0, e2, h7->face());
      h8->setNeighbors(h8->next(), h2, v3, e3, h8->face());
      h9->setNeighbors(h9->next(), h4, v1, e4, h9->face());

      //vertices
      v0->halfedge() = h2;
      v1->halfedge() = h5;
      v2->halfedge() = h3;
      v3->halfedge() = h0;
      
      //edges
      e0->halfedge() = h0;
      e1->halfedge() = h5;
      e2->halfedge() = h1;
      e3->halfedge() = h2;
      e4->halfedge() = h4;
      
      //faces
      f0->halfedge() = h0;
      f1->halfedge() = h3;
      
    return e0;
  }

  VertexIter HalfedgeMesh::splitEdge( EdgeIter e0 )
  {
    // TODO Part 5.
    // TODO This method should split the given edge and return an iterator to the newly inserted vertex.
    // TODO The halfedge of this vertex should point along the edge that was split, rather than the new edges.
      if (e0->isBoundary())
          return e0->halfedge()->vertex();
      
      ///COLLECT ELEMENTS
      //half edges
      HalfedgeIter h0 = e0->halfedge();
      HalfedgeIter h1 = h0->next();
      HalfedgeIter h2 = h1->next();
      HalfedgeIter h3 = h0->twin();
      HalfedgeIter h4 = h3->next();
      HalfedgeIter h5 = h4->next();
      HalfedgeIter h6 = h1->twin();
      HalfedgeIter h7 = h2->twin();
      HalfedgeIter h8 = h4->twin();
      HalfedgeIter h9 = h5->twin();
      
      //vertices
      VertexIter v0 = h0->vertex();
      VertexIter v1 = h3->vertex();
      VertexIter v2 = h2->vertex();
      VertexIter v3 = h5->vertex();
      
      //edges
      EdgeIter e1 = h1->edge();
      EdgeIter e2 = h2->edge();
      EdgeIter e3 = h4->edge();
      EdgeIter e4 = h5->edge();
      
      //faces
      FaceIter f0 = h0->face();
      FaceIter f1 = h3->face();
      
      //ALLOCATE NEW ELEMENTS
      //halfedges
      HalfedgeIter h10 = newHalfedge();
      HalfedgeIter h11 = newHalfedge();
      HalfedgeIter h12 = newHalfedge();
      HalfedgeIter h13 = newHalfedge();
      HalfedgeIter h14 = newHalfedge();
      HalfedgeIter h15 = newHalfedge();
      
      //vertices
      VertexIter v4 = newVertex();
      v4->position = (v1->position + v0->position)/2;
      
      //edges
      EdgeIter e5 = newEdge();
      EdgeIter e6 = newEdge();
      EdgeIter e7 = newEdge();
      
      //faces
      FaceIter f2 = newFace();
      FaceIter f3 = newFace();
      
      //REASSIGN ELEMENTS
      //halfedges
      h0->vertex() = v4;
      h2->setNeighbors(h0, h14, v2, e6, f0);
      h4->setNeighbors(h5, h15, v4, e7, f1);
      h7->twin() = h10;
      h8->twin() = h13;
      h10->setNeighbors(h11, h7, v2, e2, f2);
      h11->setNeighbors(h14, h12, v0, e5, f2);
      h12->setNeighbors(h13, h11, v4, e5, f3);
      h13->setNeighbors(h15, h8, v0, e3, f3);
      h14->setNeighbors(h10, h2, v4, e6, f2);
      h15->setNeighbors(h12, h4, v3, e7, f3);
      
      //vertices
      v0->halfedge() = h11;
      v4->halfedge() = h0;
      
      //edges
      e2->halfedge() = h10;
      e3->halfedge() = h13;
      e5->halfedge() = h11;
      e6->halfedge() = h2;
      e7->halfedge() = h4;
      
      //faces
      f2->halfedge() = h11;
      f3->halfedge() = h12;
      
      return v4;
  }

  void MeshResampler::upsample( HalfedgeMesh& mesh )
  {
    // TODO Part 6.
    // This routine should increase the number of triangles in the mesh using Loop subdivision.
    // Each vertex and edge of the original surface can be associated with a vertex in the new (subdivided) surface.
    // Therefore, our strategy for computing the subdivided vertex locations is to *first* compute the new positions using the connectity of the original (coarse) mesh; navigating this mesh will be much easier than navigating the new subdivided (fine) mesh, which has more elements to traverse. We will then assign vertex positions in the new mesh based on the values we computed for the original mesh.
      

    // TODO Compute new positions for all the vertices in the input mesh, using the Loop subdivision rule, and store them in Vertex::newPosition. At this point, we also want to mark each vertex as being a vertex of the original mesh.
      float u = 0; float n = 0;
      for( VertexIter v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++ ) {
          v->isNew = false;
          
          n = v->degree();
          if (n == 3)
              u = 3.0/16.0;
          else
              u = 3.0/(8.0 * n);
          v->computeCentroid();
          v->newPosition = (1 - n * u) * v->position + u * v->centroid * n;
      }

    // TODO Next, compute the updated vertex positions associated with edges, and store it in Edge::newPosition.
      Vector3D A, B, C, D;
      for( EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++ ) {
          e->isNew = false;
          A = e->halfedge()->vertex()->position;
          B = e->halfedge()->twin()->vertex()->position;
          C = e->halfedge()->next()->next()->vertex()->position;
          D = e->halfedge()->twin()->next()->next()->vertex()->position;
          e->newPosition = 3.0/8.0 * (A + B) + (1.0/8.0) * (C + D);
      }

    // TODO Next, we're going to split every edge in the mesh, in any order.  For future reference, we're also going to store some information about which subdivided edges come from splitting an edge in the original mesh, and which edges are new, by setting the flat Edge::isNew.  Note that in this loop, we only want to iterate over edges of the original mesh---otherwise, we'll end up splitting edges that we just split (and the loop will never end!)
      //EdgeIter eEnd = mesh.edgesEnd();
      EdgeIter e = mesh.edgesBegin();
      int num = mesh.nEdges();
      for (int i = 0; i < num; i++) {
          VertexIter v = mesh.splitEdge(e);
          v->isNew = true;
          v->newPosition = e->newPosition;
          v->halfedge()->edge()->isNew = false; //e0
          v->halfedge()->twin()->next()->edge()->isNew = true; //e7
          v->halfedge()->next()->next()->edge()->isNew = true; //e2
          v->halfedge()->twin()->next()->twin()->next()->edge()->isNew = false; //e5
          e++;
      }
      VertexIter v0, v1;
    // TODO Now flip any new edge that connects an old and new vertex.
      for ( EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++) {
          if (e->isNew) {
              v0 = e->halfedge()->vertex();
              v1 = e->halfedge()->twin()->vertex();
              if ((v0->isNew and !v1->isNew) or (!v0->isNew and v1->isNew)) {
                  mesh.flipEdge(e);
              }
          }
      }

    // TODO Finally, copy the new vertex positions into final Vertex::position.
      for( VertexIter v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++ ) {
            v->position = v->newPosition;
      }
    return;
  }
    
    void Vertex::computeCentroid() {
        HalfedgeCIter h = halfedge();    // get one of the outgoing halfedges of the vertex
        HalfedgeCIter og = h;
        Vector3D sum = 0;
        do {
            HalfedgeCIter h_twin = h->twin(); // get the vertex of the current halfedge
            VertexCIter v = h_twin->vertex(); // vertex is 'source' of the half edge.
            // so h->vertex() is v,
            // whereas h_twin->vertex() is the neighbor vertex.
            sum += v->position;
            h = h_twin->next();               // move to the next outgoing halfedge of the vertex.
        } while(h != og);        // keep going until we're back at the beginning
        centroid = sum/degree();
        return;
    }
}
