#include "s21_graph.h"

namespace s21 {
    Graph::Graph(const std::vector<std::vector<int> >& matrix)
            : m_matrix{matrix}, m_dimension{static_cast<int>(matrix.size())} {}

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

        std::cout << "\nLoading complete!";
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
                    outfile << " " << i << " -- " << j << " [weight=\"" << m_matrix[i][j] << "\"];\n";
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

        std::vector<int> neighboors;
        for (int i = 0; i < m_dimension; ++i) {
            if (m_matrix[vertex][i] != 0) {
                neighboors.push_back(i);
            }
        }
        return neighboors;
    }

    int Graph::getNumVertices() const {
        return m_dimension;
    }


    void Graph::printGraph() const {
        std::cout << "\nPRINTING:  \n";
        for (int i = 0; i  < m_dimension; i++) {
            for (int j = 0; j < m_dimension; j++) {
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

}  // namespace s21
