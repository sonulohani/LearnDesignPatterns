#include <bits/stdc++.h>

using namespace std;

class IProcessor{
public:
    virtual void process(int input) = 0;
protected:
    IProcessor *m_pParentProcessor = nullptr;
};

class NegativeProcessor : public IProcessor{
public:
    explicit NegativeProcessor(IProcessor *processor)
    {
        m_pParentProcessor = processor;
    }
    void process(int input) override
    {
        if(input < 0) {
            cout << "Negative Processor\n";
        }
        else if(m_pParentProcessor == nullptr)
        {
            cerr << "Error";
        }
        else{
            m_pParentProcessor->process(input);
        }
    }
};

class PositiveProcessor : public IProcessor
{
public:
    explicit PositiveProcessor(IProcessor *processor)
    {
        m_pParentProcessor = processor;
    }
    void process(int input) override{
        if(input > 0) {
            cout << "Positive Processor\n";
        }
        else if(m_pParentProcessor == nullptr)
        {
            cerr << "Error";
        }
        else{
            m_pParentProcessor->process(input);
        }
    }
};

class ZeroProcessor : public IProcessor
{
public:
    explicit ZeroProcessor(IProcessor *processor)
    {
        m_pParentProcessor = processor;
    }
    void process(int input) override{
        if(input == 0) {
            cout << "Zero Processor\n";
        }
        else if(m_pParentProcessor == nullptr)
        {
            cerr << "Error";
        }
        else{
            m_pParentProcessor->process(input);
        }
    }
};

class Chain{
public:
    void setProcessor(IProcessor *processor)
    {
        this->m_pProcessor = processor;
    }
    void process(int input)
    {
        m_pProcessor->process(input);
    }
private:
    IProcessor *m_pProcessor = nullptr;

};

int main()
{
    auto processor = new NegativeProcessor(new PositiveProcessor(new ZeroProcessor(nullptr)));
    Chain ch;
    ch.setProcessor(processor);
    ch.process(342);
}
