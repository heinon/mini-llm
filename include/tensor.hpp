#pragma once

#include <vector>

class Tensor
{
public:
    Tensor(std::vector<int> shape);

    float get(std::vector<int>& index) const;
    int offset(std::vector<int>& index) const;
    
    void fill_(std::vector<float> data);
    Tensor& zeros_();
    Tensor& ones_();
    Tensor& fill_(float value);

    Tensor reshape(std::vector<int> shape);
    void print() const;
private:
    std::vector<float> data_;
    std::vector<int> shape_;
    std::vector<int> strides_;
    std::vector<int> computeStrides(std::vector<int>& shape);
    int numel() const;
};