#include "s21_graph.h"

namespace s21 {
    void Graph::loadGraphFromFile(std::string filename) {
        std::ifstream loadfile(filename);
        if (!loadfile.is_open()) {
            throw std::invalid_argument("File not found");
        }

        loadfile >> m_dimension;
        m_matrix.resize(m_dimension);
        for (int i = 0; i < m_dimension; ++i) {
            m_matrix[i].resize((m_dimension));
            for (int j = 0; j < m_dimension; ++j) {
                loadfile >> m_matrix[i][j];
            }
        }

    }

    void Graph::exportGraphToDot(std::string filename) const {
        std::ofstream outfile(filename);
        if (!outfile) {
            throw std::invalid_argument("Can\'t open file");
        }

        outfile << "digraph G {\n";
        for (int i = 0; i < m_dimension; ++i) {
            for (int j = 0; j < m_dimension; ++j) {
                if (m_matrix[i][j] != 0) {
                    outfile << " " << i + 1 << " -- " << j + 1 << " [weight=\"" << m_matrix[i][j] << "\"];\n";
                }
            }
        }
        outfile << "}";
        outfile.close();
        std::cout << "\nExport is finished";
    }

    std::vector<int> Graph::getNeighbors(int vertex) const {
        if (vertex < 0 || vertex >= m_dimension) {
            throw std::out_of_range("Vertex index out of range");
        }

        std::vector<int> neighbors;
        for (int i = 0; i < m_dimension; ++i) {
            if (m_matrix[vertex][i] != 0) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    int Graph::getNumVertices() const {
        return m_dimension;
    }

    std::vector<int> Graph::getAdjacent(int current_index) {
        std::vector<int> adj_vertices;

        if (current_index >= 0 && current_index < m_dimension) {
            for (int i = 0; i < m_dimension; ++i) {
                if (m_matrix[current_index][i] != 0) {
                    adj_vertices.push_back(i);
                }
            }
        }
        return adj_vertices;
    }

    double Graph::getDistance(int current_vertex, int next_vertex) {
        return m_matrix[current_vertex][next_vertex];
    }
}  // namespace s21
