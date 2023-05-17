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

        // ВЫНЕСТИ В UI И В ОТДЕЛЬНУЮ ФУНКЦИЮ
        int delay = 30;
        std::string textLoading = "\nLOADING SUCCESSFULLY COMPLETE!";
        for (std::size_t i = 0; i < textLoading.length(); i++) {
            std::cout << textLoading[i] << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
        std::cout << std::endl;

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

    void Graph::printGraph() const {
        std::cout << "\nPRINTING:  \n";
        for (int i = 1; i  < m_dimension; i++) {
            for (int j = 1; j < m_dimension; j++) {
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


}  // namespace s21
