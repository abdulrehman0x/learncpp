#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <charconv>
#include <stdexcept>
#include <cmath>

namespace MathTools {

    struct TableConfig {
        int baseNumber = 1;
        int maxMultiplier = 10;
        int columnWidth = 6;   // will be adjusted dynamically inside render()
    };

    class MultiplicationTableGenerator {
    public:
        explicit MultiplicationTableGenerator(const TableConfig& config)
            : config_(config) {}

        void render(std::ostream& os) const {
            // Calculate required width for the largest product
            long long maxProduct = static_cast<long long>(config_.baseNumber) * config_.maxMultiplier;
            int width = static_cast<int>(std::to_string(std::abs(maxProduct)).length()) + 2; // sign + space
            if (width < config_.columnWidth) {
                width = config_.columnWidth;
            }

            printHeader(os, width);
            printBody(os, width);
            printFooter(os);
        }

    private:
        TableConfig config_;

        void printHeader(std::ostream& os, int width) const {
            os << "\n========================================\n";
            os << "       MULTIPLICATION TABLE FOR " << config_.baseNumber << "\n";
            os << "========================================\n";
            os << std::setw(10) << "Factor"
               << std::setw(5)  << "x"
               << std::setw(10) << "Multiplier"
               << std::setw(5)  << "="
               << std::setw(width) << "Result" << "\n";
            os << "----------------------------------------\n";
        }

        void printBody(std::ostream& os, int width) const {
            for (int i = 1; i <= config_.maxMultiplier; ++i) {
                long long result = static_cast<long long>(config_.baseNumber) * i;
                os << std::setw(10) << config_.baseNumber
                   << std::setw(5)  << "x"
                   << std::setw(10) << i
                   << std::setw(5)  << "="
                   << std::setw(width) << result << "\n";
            }
        }

        void printFooter(std::ostream& os) const {
            os << "========================================\n\n";
        }
    };

    class InputHandler {
    public:
        static int getValidInt(std::istream& in,
                               std::ostream& out,
                               const std::string& prompt,
                               int minVal = std::numeric_limits<int>::min(),
                               int maxVal = std::numeric_limits<int>::max()) {
            while (true) {
                // std::flush forces the buffer to display prompt immediately even when streams are untied
                out << prompt << std::flush;

                std::string input;
                if (!std::getline(in, input)) {
                    throw std::runtime_error("Input stream closed unexpectedly.");
                }

                if (input.empty()) {
                    out << "[Error] Input cannot be empty. Please try again.\n";
                    continue;
                }

                int value{};
                auto [ptr, ec] = std::from_chars(input.data(), input.data() + input.size(), value);

                if (ec == std::errc::invalid_argument) {
                    out << "[Error] Invalid input. Please enter a valid integer.\n";
                } else if (ec == std::errc::result_out_of_range) {
                    out << "[Error] Number out of range for int.\n";
                } else if (ptr != input.data() + input.size()) {
                    out << "[Error] Input contains trailing characters.\n";
                } else if (value < minVal || value > maxVal) {
                    out << "[Error] Value must be between " << minVal << " and " << maxVal << ".\n";
                } else {
                    return value;
                }
            }
        }
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    try {
        std::cout << "--- Production-Grade Multiplication Table Generator ---\n\n" << std::flush;

        int base = MathTools::InputHandler::getValidInt(
            std::cin, std::cout,
            "Enter the base number (-100,000 to 100,000): ",
            -100000, 100000);

        int range = MathTools::InputHandler::getValidInt(
            std::cin, std::cout,
            "Enter the range/max multiplier (1 to 10,000): ",
            1, 10000);

        MathTools::TableConfig config;
        config.baseNumber = base;
        config.maxMultiplier = range;

        MathTools::MultiplicationTableGenerator generator(config);
        generator.render(std::cout);

    } catch (const std::exception& e) {
        std::cerr << "\n[Fatal Error] " << e.what() << "\n";
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "\n[Fatal Error] Unknown error occurred.\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
