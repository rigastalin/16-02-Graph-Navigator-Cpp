#include "s21_graph.h"

namespace s21 {
    Graph::Graph(const std::vector<std::vector<int> >& matrix)
            : m_matrix{matrix}, m_dimension{static_cast<int>(matrix.size())} {}

    void Graph::loadGraphFromFile(std::string filename) {
        std::ifstream loadfile(filename);
        if (!loadfile.is_open()) {
            throw std::invalid_argument("File not found");
        }

        int matrix_size;
        loadfile >> matrix_size;
        m_matrix.resize(matrix_size);
        for (int i = 0; i < matrix_size; ++i) {
            m_matrix[i].resize((matrix_size));
            for (int j = 0; j < matrix_size; ++j) {
                loadfile >> m_matrix[i][j];
            }
        }

        std::cout << "\nPRINTING: \n";
        for (int i = 0; i  < m_dimension; i++) {
            for (int j = 0; j < m_dimension; j++) {
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }


        std::cout << "\nLoading complete!";
    }

    void Graph::exportGraphToDot(std::string filename) const {
        std::ofstream outfile(filename);
        if (!outfile) {
            throw std::invalid_argument("Can\'t open file");
        }

        outfile << "digraph graphname {\n";
        for (int i = 0; i < m_dimension; ++i) {
            for (int j = 0; j < m_dimension; ++j) {
                if (m_matrix[i][j] != 0) {
                    outfile << " " << i << " -> " << j << " [label=\"" << m_matrix[i][j] << "\"];\n";
                }
            }
        }
        outfile << "}";
        outfile.close();
        std::cout << "\nExport is finished";
    }

    void Graph::printGraph() const {
        std::cout << "\nAdjacency matrix: \n";
        for (int i = 0; i  < m_dimension; i++) {
            for (int j = 0; j < m_dimension; j++) {
                std::cout << m_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

}  // namespace s21
