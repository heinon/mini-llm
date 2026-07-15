#include "tensor.hpp"
#include <iostream>

Tensor::Tensor(std::vector<int> shape) : shape_(std::move(shape)), strides_(computeStrides(shape))
{
    auto total = numel();
    data_.resize(total);
}

std::vector<int> Tensor::computeStrides(std::vector<int>& shape)
{
    std::vector<int> strides(shape.size());
    int stride = 1;
    for (int i = shape.size() - 1; i >= 0; i--)
    {
        strides[i] = stride;
        stride = stride * shape[i];
    }

    return strides;
}

void Tensor::print() const
{
    std::cout << numel() << std::endl;
}

int Tensor::numel() const
{
    int total = 1;
    for (int dim : shape_)
    {
        total = total * dim;
    }

    return total;
}