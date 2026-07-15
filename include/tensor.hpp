#pragma once

#include <vector>

class Tensor
{
public:
    Tensor(std::vector<int> shape);

    void print() const;
private:
    std::vector<float> data_;
    std::vector<int> shape_;
    std::vector<int> strides_;

    std::vector<int> computeStrides(std::vector<int>& shape);
    int numel() const;
};