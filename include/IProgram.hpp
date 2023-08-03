#pragma once

class IProgram
{
public:
    virtual ~IProgram() {}
    virtual void run() = 0;
};
