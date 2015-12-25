#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

graph create_graph() {
  graph ret;
  ret.vertices = make_jrb();
  ret.edges = make_jrb();
  return ret;
}

void add_vertex(graph graph, int id, char *value) {
  if (graph.edges == NULL || graph.vertices == NULL)
    return;

  JRB node = jrb_find_int(graph.vertices, id);
  if (node == NULL) {
    jrb_insert_int(graph.vertices, id, new_jval_s(value));
  }


}

char *get_vertex(graph graph, int id) {
  if (graph.edges == NULL || graph.vertices == NULL)
    return NULL;

  JRB node = jrb_find_int(graph.vertices, id);
  if (node != NULL) {
    return jval_s(node->val);
  }

  return NULL;

}


void add_edge(graph g, int v, int v2, double weight) {
  if (has_edge(g, v, v2))
    return;

#define ADD_EDGE_MACRO(v, v2)  {                                \
         JRB node = jrb_find_int(g.edges, v);                   \
         JRB tree;                                              \
         if(node == NULL){                                      \
           tree = make_jrb();                                   \
           jrb_insert_int(g.edges, v, new_jval_v(tree));        \
         }                                                      \
         else                                                   \
           tree = (JRB) jval_v(node->val);                      \
         jrb_insert_int(tree, v2, new_jval_d(weight));          \
                                                                \
       } while(0);

  ADD_EDGE_MACRO(v, v2);

  ADD_EDGE_MACRO(v2, v);

#undef ADD_EDGE_MACRO

}

int has_edge(graph g, int v, int v2) {
  if (g.edges == NULL || g.vertices == NULL)
    return 0;

  JRB node = jrb_find_int(g.edges, v);
  JRB tree;
  if (node == NULL)
    return 0;
  tree = (JRB) jval_v(node->val);
  JRB f = jrb_find_int(tree, v2);
  if (f != NULL)
    return 1;
  return 0;

}

double get_edge_val(graph g, int v, int v2) {
  if (!has_edge(g, v, v2))
    return INFINITY;

  JRB node = jrb_find_int(g.edges, v);
  JRB tree = (JRB) jval_v(node->val);
  JRB f = jrb_find_int(tree, v2);
  return jval_d(f->val);
}

int out_degree(graph g, int vertex, int *output) {
  if (g.edges == NULL || g.vertices == NULL)
    return 0;
  JRB node = jrb_find_int(g.edges, vertex);
  if (node == NULL)
    return 0;
  int total = 0;
  JRB tree;
  tree = (JRB) jval_v(node->val);
  jrb_traverse(node, tree)
  output[total++] = jval_i(node->key);
  return total;
}

int in_degree(graph g, int vertex, int *output) {

  if (g.edges == NULL || g.vertices == NULL)
    return 0;


  JRB node = jrb_find_int(g.vertices, vertex);
  if (node == NULL)
    return 0;

  int total = 0;

  jrb_traverse(node, g.vertices) {
    if (has_edge(g, jval_i(node->key), vertex)) {
      output[total++] = jval_i(node->key);
    }
  }

  return total;
}

void drop_graph(graph *g) {

  JRB node;
  jrb_traverse(node, g->edges)
  jrb_free_tree(jval_v(node->val));
  jrb_free_tree(g->vertices);
  jrb_free_tree(g->edges);

}

void BFS(graph g, int start, int stop, void (*visited_func)(graph, int)) {
  if (g.edges == NULL || g.vertices == NULL)
    return;
  JRB tmp;
  int v = 0;
  jrb_traverse(tmp, g.vertices) {
    v++;
  }

  int *visited = (int*)malloc(v * sizeof(int));
  if (visited == NULL) {
    fprintf(stderr, "Allocated failed in %s:%d \n", __FILE__, __LINE__);
    exit(1);
  }

  int i;
  for (i = 0; i < v; i++) visited[i] = 0;

  Dllist queue = new_dllist();



  // add start node to queue
  JRB node = jrb_find_int(g.vertices, start);
  if (node == NULL)
    goto end;


  dll_append(queue, new_jval_i(start));
  //



  while (!dll_empty(queue)) {
    Dllist node = dll_first(queue);
    int u = jval_i(node->val);
    dll_delete_node(node);

    if (!visited[u]) {
      visited_func(g, u);
      visited[u] = 1;
    }

    if (u == stop)
      goto end;

    JRB u_node = jrb_find_int(g.edges, u);
    if (u_node == NULL)
      continue;

    JRB vertex_connect_to_u_tree = (JRB)(jval_v(u_node->val));


    jrb_traverse(tmp, vertex_connect_to_u_tree) {
      if (!visited[tmp->key.i])
        dll_append(queue, new_jval_i(tmp->key.i));
    }
  }
end:
  free(visited);
  free_dllist(queue);
}

void DFS(graph g, int start, int stop, void (*visited_func)(graph, int)) {
  if (g.edges == NULL || g.vertices == NULL)
    return;
  JRB tmp;
  int v = 0;
  jrb_traverse(tmp, g.vertices) {
    v++;
  }

  int *visited = (int*)malloc(v * sizeof(int));
  if (visited == NULL) {
    fprintf(stderr, "Allocated failed in %s:%d \n", __FILE__, __LINE__);
    exit(1);
  }

  int i;
  for (i = 0; i < v; i++) visited[i] = 0;

  Dllist stack = new_dllist();



  // add start node to stack
  JRB node = jrb_find_int(g.edges, start);
  if (node == NULL)
    goto end;


  dll_append(stack, new_jval_i(start));
  //



  while (!dll_empty(stack)) {
    Dllist node = dll_last(stack);
    int u = jval_i(node->val);
    dll_delete_node(node);

    if (!visited[u]) {
      visited_func(g, u);
      visited[u] = 1;
    }

    if (u == stop)
      goto end;

    JRB u_node = jrb_find_int(g.edges, u);
    if (u_node == NULL)
      continue;

    JRB vertex_connect_to_u_tree = (JRB)(jval_v(u_node->val));


    jrb_rtraverse(tmp, vertex_connect_to_u_tree) {
      if (!visited[tmp->key.i])
        dll_append(stack, new_jval_i(tmp->key.i));
    }
  }

end:
  free(visited);
  free_dllist(stack);
}

int get_graph_node_num(graph g) {
  if (g.edges == NULL || g.vertices == NULL)
    return 0;
  JRB tmp;
  int v = 0;
  jrb_traverse(tmp, g.vertices) {
    v++;
  }
  return v;
}

int is_cyclic_util(graph g, int start) {
  if (g.edges == NULL || g.vertices == NULL)
    return 0;
  JRB tmp;
  int v = 0;
  jrb_traverse(tmp, g.vertices) {
    v++;
  }

  int *visited = (int*)malloc(v * sizeof(int));
  if (visited == NULL) {
    fprintf(stderr, "Allocated failed in %s:%d \n", __FILE__, __LINE__);
    exit(1);
  }

  int i;
  for (i = 0; i < v; i++) visited[i] = 0;

  Dllist stack = new_dllist();



  // add start node to stack
  JRB node = jrb_find_int(g.vertices, start);
  if (node == NULL)
    goto end;


  dll_append(stack, new_jval_i(start));
  //



  while (!dll_empty(stack)) {
    Dllist node = dll_last(stack);
    int u = jval_i(node->val);
    dll_delete_node(node);

    if (!visited[u]) {
      visited[u] = 1;
    }

    if (u == start) {
      free(visited);
      free_dllist(stack);
      return 1;
    }

    JRB u_node = jrb_find_int(g.vertices, u);
    if (u_node == NULL)
      continue;

    JRB vertex_connect_to_u_tree = (JRB)(jval_v(u_node->val));


    jrb_rtraverse(tmp, vertex_connect_to_u_tree) {
      if (!visited[tmp->key.i])
        dll_append(stack, new_jval_i(tmp->key.i));
    }
  }

end:
  free(visited);
  free_dllist(stack);
  return 0;
}

int is_cyclic(graph g) {
  if (g.edges == NULL || g.vertices == NULL)
    return 0;
  JRB tmp;
  int v = 0;
  jrb_traverse(tmp, g.vertices) {
    v++;
    if (is_cyclic_util(g, v))
      return 1;
  }
  return 0;
}

void TSort(graph g, void (*visited_func)(graph, int)) {
  if (g.edges == NULL || g.vertices == NULL)
    return;

  Dllist queue = new_dllist();
  JRB tmp;

  JRB node = jrb_find_int(g.vertices, 0);
  if (node == NULL)
    goto end;

  int v = 0, num_node = get_graph_node_num(g); // ---------------------------------
  int *in_degree_node = malloc(sizeof(int) * num_node);
  if (in_degree_node == NULL) {
    fprintf(stderr, "%s in %s:%d !!\n", "malloc failed", __FILE__, __LINE__);
    exit(1);
  }

  int *in_degree_arr = malloc(sizeof(int) * num_node);
  if (in_degree_arr == NULL) {
    fprintf(stderr, "%s in %s:%d !!\n", "malloc failed", __FILE__, __LINE__);
    exit(1);
  }

  jrb_traverse(tmp, g.vertices) {
    if ((in_degree_arr[v] = in_degree(g, v, in_degree_node)) == 0) {
      dll_append(queue, new_jval_i(v));
    }
    v++;
  }
  free(in_degree_node);
  while (!dll_empty(queue)) {
    Dllist node = dll_first(queue);
    int u = jval_i(node->val);
    dll_delete_node(node);

    visited_func(g, u);

    int *out_degree_node_u = malloc(sizeof(int) * num_node);
    if (out_degree_node_u == NULL) {
      fprintf(stderr, "%s in %s:%d !!\n", "malloc failed", __FILE__, __LINE__);
      exit(1);
    }

    int out_degree_u;
    if ((out_degree_u = out_degree(g, u, out_degree_node_u)) != 0) {
      int w, i;
      int *in_degree_node_w = malloc(sizeof(int) * num_node);
      if (in_degree_node_w == NULL) {
        fprintf(stderr, "%s in %s:%d !!\n", "malloc failed", __FILE__, __LINE__);
        exit(1);
      }
      for (i = 0; i < out_degree_u; ++i)
      {
        w = out_degree_node_u[i];

        in_degree_arr[w] -= 1;

        if (in_degree_arr[w] == 0) {
          dll_append(queue, new_jval_i(w));
        }
      }
      free(in_degree_node_w);
    }
    free(out_degree_node_u);
  }

end:
  free(in_degree_arr);
  free_dllist(queue);
}

double shortest_path(graph graph, int s, int t, int* path, double* length) {
  if (graph.edges == NULL || graph.vertices == NULL)
    return INFINITY;

  if (path == NULL || length == NULL)
    return INFINITY;

  int i, max_node = get_graph_node_num(graph);
  double *dist = malloc(sizeof(double) * max_node);  // free ?
  int *prev = malloc(sizeof(int) * max_node);
  if (!dist || !prev) {
    fprintf(stderr, "%s%s:%d\n", "Allocated Failed in ", __FILE__, __LINE__);
    exit(1);
  }

  Dllist queue = new_dllist();   // free ?

  for (i = 0; i < max_node; ++i) {
    if (i != s) {
      dist[i] = INFINITY;
      prev[i] = UNDEFINED;
    }
    dll_append(queue, new_jval_i(i));
  }

  dist[s] = 0;

  while (!dll_empty(queue)) {
    // extract min
    int u;
    {
      Dllist tmp, min_node = dll_first(queue);
      int min = jval_i(dll_first(queue)->val);
      dll_traverse(tmp, queue) {
        int tmp_node_i = jval_i(tmp->val);
        if (dist[min] > dist[tmp_node_i]) {
          min = tmp_node_i;
          min_node = tmp;
        }
      }
      u = min;
      dll_delete_node(min_node);
    }

    //
    int *out_degree_u_list = malloc(sizeof(int) * max_node);  // free ?
    if (!out_degree_u_list) {
      fprintf(stderr, "%s%s:%d\n", "Allocated Failed in ", __FILE__, __LINE__);
      exit(1);
    }
    int out_degree_u = out_degree(graph, u, out_degree_u_list);
    if (out_degree_u == 0)
      continue;

    int i;
    for (i = 0; i < out_degree_u; i++) {
      int v = out_degree_u_list[i];
      int alt = dist[u] + get_edge_val(graph, u, v);
      if (alt < dist[v]) {
        dist[v] = alt;
        prev[v] = u;
        dll_append(queue, new_jval_i(v));
      }

    }
    free(out_degree_u_list);
  
  }

  for (i = 0; i < max_node; i++){
    length[i] = dist[i];
    path[i] = prev[i]; // fix ??
  }



  return dist[t];

  ///
  free_dllist(queue);
  free(dist);
  free(prev);
  return 3;
}