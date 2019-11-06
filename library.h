#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <range/v3/all.hpp>

using Byte = unsigned char;
using IP = std::vector<Byte>;
using IPPool = std::vector<IP>;

Byte stob(const std::string &data);
IP parse_ip(const std::string &line);
void read_ip_pool(IPPool &ip_pool);
void sort_ip_pool(IPPool &ip_pool);
void print_ip(const IP &ip);
void print_ip_pool(const IPPool &ip_pool);

auto filter = [](const IPPool &ip_pool, auto ...params) {
    IP sample = { (Byte(params))... };
    IPPool result;
    auto begin = ranges::upper_bound(ip_pool, sample, [](const IP &sample, const IP &ip) {
        return sample > ip || std::equal(sample.cbegin(), sample.cend(), ip.cbegin());
    });
    auto end = ranges::lower_bound(ip_pool, sample, std::greater<IP>());
    std::copy(begin, end, std::back_inserter(result));
    return result;
};

auto filter_any = [](const IPPool &ip_pool, auto param) {
    return ip_pool | ranges::view::filter([param](const IP &ip) {
        return ranges::any_of(ip, [param](Byte byte) {
            return param == byte;
        });
    });
};
