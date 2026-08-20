#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Order {
    int id;
    std::string type; // "BUY" or "SELL"
    double price;
    int quantity;
};

void matchOrders(std::vector<Order>& buys, std::vector<Order>& sells) {
    // Sort buys descending (highest price first), sells ascending (lowest price first)
    std::sort(buys.begin(), buys.end(), [](const Order& a, const Order& b) { return a.price > b.price; });
    std::sort(sells.begin(), sells.end(), [](const Order& a, const Order& b) { return a.price < b.price; });

    std::cout << "\n=========================================\n";
    std::cout << "     MATCHING ENGINE EXECUTING...        \n";
    std::cout << "=========================================\n";

    bool anyTradeExecuted = false;

    for (auto buyIt = buys.begin(); buyIt != buys.end(); ) {
        bool matched = false;
        for (auto sellIt = sells.begin(); sellIt != sells.end(); ) {
            if (buyIt->price >= sellIt->price) { // Trade condition met
                int tradedQty = std::min(buyIt->quantity, sellIt->quantity);
                std::cout << " [TRADE EXECUTION] " << tradedQty << " units @ $" << sellIt->price
                          << " (Buy Order #" << buyIt->id << " <-> Sell Order #" << sellIt->id << ")\n";

                anyTradeExecuted = true;
                buyIt->quantity -= tradedQty;
                sellIt->quantity -= tradedQty;

                if (sellIt->quantity == 0) sellIt = sells.erase(sellIt);
                else ++sellIt;

                if (buyIt->quantity == 0) {
                    buyIt = buys.erase(buyIt);
                    matched = true;
                    break;
                }
            } else {
                ++sellIt;
            }
        }
        if (!matched) ++buyIt;
    }

    if (!anyTradeExecuted) {
        std::cout << " No overlapping prices. No trades executed.\n";
    }
    std::cout << "=========================================\n\n";
}

void printUnmatchedOrders(const std::vector<Order>& buys, const std::vector<Order>& sells) {
    std::cout << "--- CURRENT UNMATCHED ORDER BOOK ---\n";
    std::cout << "BUY ORDERS:\n";
    if (buys.empty()) std::cout << "  (None)\n";
    for (const auto& b : buys) {
        std::cout << "  [ID " << b.id << "] " << b.quantity << " units @ $" << b.price << "\n";
    }

    std::cout << "SELL ORDERS:\n";
    if (sells.empty()) std::cout << "  (None)\n";
    for (const auto& s : sells) {
        std::cout << "  [ID " << s.id << "] " << s.quantity << " units @ $" << s.price << "\n";
    }
    std::cout << "------------------------------------\n\n";
}

int main() {
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
    int orderCounter = 1; // Automatically assigns unique IDs

    std::cout << "=== INTERACTIVE ORDER BOOK ENGINE ===\n";

    while (true) {
        std::cout << "Select Action: [1] Add BUY Order  [2] Add SELL Order  [3] View Order Book  [4] Exit\n Choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting program.\n";
            break;
        }

        if (choice == 4) {
            std::cout << "Shutting down Order Engine. Goodbye!\n";
            break;
        }

        if (choice == 3) {
            printUnmatchedOrders(buyOrders, sellOrders);
            continue;
        }

        if (choice == 1 || choice == 2) {
            double price;
            int quantity;

            std::cout << " Enter Price ($): ";
            std::cin >> price;
            std::cout << " Enter Quantity: ";
            std::cin >> quantity;

            if (choice == 1) {
                Order newBuy = {orderCounter++, "BUY", price, quantity};
                buyOrders.push_back(newBuy);
                std::cout << "\n--> Placed BUY Order #" << newBuy.id << " (" << quantity << " units @ $" << price << ")\n";
            } else {
                Order newSell = {orderCounter++, "SELL", price, quantity};
                sellOrders.push_back(newSell);
                std::cout << "\n--> Placed SELL Order #" << newSell.id << " (" << quantity << " units @ $" << price << ")\n";
            }

            // Immediately run the engine to check if the new order triggers a trade
            matchOrders(buyOrders, sellOrders);
        } else {
            std::cout << "Invalid choice. Please pick 1, 2, 3, or 4.\n\n";
        }
    }

    return 0;
}
