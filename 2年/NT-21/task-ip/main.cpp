#include <iostream>
#include <sstream>
#include <vector>

std::string calculate_network_mask(const std::string& ip_address, const std::string& subnet_mask) {
    std::vector<std::string> ip_octets;
    std::vector<std::string> subnet_octets;
    std::istringstream ip_stream(ip_address);
    std::istringstream subnet_stream(subnet_mask);
    std::string octet;

    while (std::getline(ip_stream, octet, '.')) {
        ip_octets.push_back(octet);
    }

    while (std::getline(subnet_stream, octet, '.')) {
        subnet_octets.push_back(octet);
    }

    std::vector<std::string> network_mask_octets;

    for (size_t i = 0; i < 4; ++i) {
        int network_mask_octet = std::stoi(ip_octets[i]) & std::stoi(subnet_octets[i]);
        network_mask_octets.push_back(std::to_string(network_mask_octet));
    }

    std::string network_mask = network_mask_octets[0] + "." + network_mask_octets[1] + "." +
                                network_mask_octets[2] + "." + network_mask_octets[3];

    return network_mask;
}

int main() {
    std::string ip_address1, subnet_mask1, ip_address2, subnet_mask2;

    std::cout << "クライアントIP： ";
    std::cin >> ip_address1;
    std::cout << "サブネット： ";
    std::cin >> subnet_mask1;
    std::cout << "サーバーIP： ";
    std::cin >> ip_address2;
    std::cout << "サブネット： ";
    std::cin >> subnet_mask2;

    std::string client_network_mask1 = calculate_network_mask(ip_address1, subnet_mask1);
    std::string client_network_mask2 = calculate_network_mask(ip_address2, subnet_mask1);
    std::string server_network_mask1 = calculate_network_mask(ip_address1, subnet_mask2);
    std::string server_network_mask2 = calculate_network_mask(ip_address2, subnet_mask2);

    std::string color, reset_color;

    if (client_network_mask1 == client_network_mask2 && server_network_mask1 == server_network_mask2) {
        color = "\033[33m";  // Yellow
    } else if (client_network_mask1 == client_network_mask2) {
        color = "\033[34m";  // Blue
    } else {
        color = "\033[31m";  // Red
    }

    reset_color = "\033[0m";

    std::cout << "クライアント視点: " << color << client_network_mask1 << "  " << client_network_mask2 << reset_color << "\n";
    std::cout << "サーバー視点: " << color << server_network_mask1 << "  " << server_network_mask2 << reset_color << "\n";

    return 0;
}
