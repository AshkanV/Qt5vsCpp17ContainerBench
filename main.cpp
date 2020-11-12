#include <QCoreApplication>
#include <QDebug>

#include <QFile>
#include <QHash>
#include <QList>
#include <QMap>
#include <QMultiHash>
#include <QMultiMap>
#include <QQueue>
#include <QSet>
#include <QStack>
#include <QVarLengthArray>
#include <QVector>

#include <algorithm>
#include <array>
#include <deque>
#include <execution>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Key_T        = int;
using Value_T      = int;
using SampleList_T = std::vector<std::pair<Key_T, Value_T> >;
using time_point   = std::chrono::system_clock::time_point;
using std::chrono::system_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::nanoseconds;

static constexpr auto TestCount{ 100 };
static constexpr auto SampleCount{ 100'000 };

SampleList_T generateSamplePairsList(int sampleCount);

QVector<Value_T>                 generateQVector(const SampleList_T & samplesList);
std::vector<Value_T>             generateStdVector(const SampleList_T & samplesList);
QVarLengthArray<Value_T>         generateQVarLengthArray(const SampleList_T & samplesList);
std::array<Value_T, SampleCount> generateStdArray(const SampleList_T & samplesList);
QList<Value_T>                   generateQList(const SampleList_T & samplesList);

QSet<Value_T>               generateQSet(const SampleList_T & samplesList);
std::set<Value_T>           generateStdSet(const SampleList_T & samplesList);
std::unordered_set<Value_T> generateStdUnorderedSet(const SampleList_T & samplesList);

QMap<Key_T, Value_T>     generateQMap(const SampleList_T & samplesList);
std::map<Key_T, Value_T> generateStdMap(const SampleList_T & samplesList);

QMultiMap<Key_T, Value_T>     generateQMultiMap(const SampleList_T & samplesList);
std::multimap<Key_T, Value_T> generateStdMultiMap(const SampleList_T & samplesList);

QHash<Key_T, Value_T>              generateQHash(const SampleList_T & samplesList);
std::unordered_map<Key_T, Value_T> generateStdUnorderedMap(const SampleList_T & samplesList);

QMultiHash<Key_T, Value_T>              generateQMultiHash(const SampleList_T & samplesList);
std::unordered_multimap<Key_T, Value_T> generateStdUnorderedMultiMap(const SampleList_T & samplesList);

std::list<Value_T> generateStdList(const SampleList_T & samplesList);

QQueue<Value_T>     generateQQueue(const SampleList_T & samplesList);
std::deque<Value_T> generateStdDeque(const SampleList_T & samplesList);

QStack<Value_T>     generateQStack(const SampleList_T & samplesList);
std::stack<Value_T> generateStdStack(const SampleList_T & samplesList);

static time_point lastTick;

inline void timeTick()
{
    lastTick = system_clock::now();
}


inline void timeTock(const QString & message)
{
    const auto FinalMessage{ message + ":" + QString(4 - (message.length() + 1) / 8, QChar('\t')) };

    qDebug()
        << FinalMessage.toStdString().c_str()
        << duration_cast<nanoseconds>(system_clock::now() - lastTick).count() / TestCount;
}


template <typename T>
inline void use(T & container)
{ if (container.size() < 10) throw; }


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Starting" << Qt::endl;

    Key_T j{};

    // Samples
    const auto SamplePairsList{ generateSamplePairsList(SampleCount) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateSamplePairsList(SampleCount) };
        use(temp);
    }
    timeTock("Generating sample");

    // Vector
    const auto SampleQVarLengthArray{ generateQVarLengthArray(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQVarLengthArray(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QVarLengthArray");

    const auto SampleStdArray{ generateStdArray(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdArray(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdArray");

    const auto SampleQVector{ generateQVector(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQVector(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QVector");

    const auto SampleStdVector{ generateStdVector(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdVector(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdVector");

    const auto SampleQList{ generateQList(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQList(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QList");

    // Set
    const auto SampleQSet{ generateQSet(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQSet(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QSet");

    const auto SampleStdUnorderedSet{ generateStdUnorderedSet(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdUnorderedSet(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdUnorderedSet");

    const auto SampleStdSet{ generateStdSet(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdSet(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdSet");

    // Map
    const auto SampleQMap{ generateQMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QMap");

    const auto SampleStdMap{ generateStdMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdMap");

    // Multi Map
    const auto SampleQMultiMap{ generateQMultiMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQMultiMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QMultiMap");

    const auto SampleStdMultiMap{ generateStdMultiMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdMultiMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdMultiMap");

    // Hash
    const auto SampleQHash{ generateQHash(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQHash(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QHash");

    const auto SampleStdUnorderedMap{ generateStdUnorderedMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdUnorderedMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdUnorderedMap");

    // Multi Hash
    const auto SampleQMultiHash{ generateQMultiHash(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQMultiHash(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QMultiHash");

    const auto SampleStdUnorderedMultiMap{ generateStdUnorderedMultiMap(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdUnorderedMultiMap(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdUnorderedMultiMap");

    // List
    const auto SampleStdList{ generateStdList(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdList(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdList");

    // Stack
    const auto SampleQStack{ generateQStack(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQStack(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QStack");

    const auto SampleStdStack{ generateStdStack(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdStack(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdStack");

    // Queue
    const auto SampleQQueue{ generateQQueue(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateQQueue(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating QQueue");

    const auto SampleStdDeque{ generateStdDeque(SamplePairsList) };
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        auto temp{ generateStdDeque(SamplePairsList) };
        use(temp);
    }
    timeTock("Generating StdQueue");

    return 0;

    u_int64_t checksum{};
    for (const auto & pair : SamplePairsList)
        checksum += pair.first;

    u_int64_t sum{};
    int       i {};

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i, sum = 0)
            sum += SampleStdArray[i];
    }
    timeTock("Accessing StdArray");
    if (sum > checksum) throw;

    // Vector
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i)
            sum += SampleQVarLengthArray[i];
    }
    timeTock("Accessing QVarLengthArray");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i)
            sum += SampleQVector[i];
    }
    timeTock("Accessing QVector");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i)
            sum += SampleStdVector[i];
    }
    timeTock("Accessing StdVector");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i)
            sum += SampleQList[i];
    }
    timeTock("Accessing QList");
    if (sum > checksum) throw;


    // Set
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (i = 0; i < SampleCount; ++i)
            sum += *SampleQSet.find(i);
    }
    timeTock("Finding QSet");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleStdUnorderedSet.find(k);
    }
    timeTock("Finding StdUnorderedSet");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleStdSet.find(k);
    }
    timeTock("Finding StdSet");
    if (sum > checksum) throw;


    // Map
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleQMap.find(k);
    }
    timeTock("Finding QMap");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += SampleStdMap.find(k)->second;
    }
    timeTock("Finding StdMap");
    if (sum > checksum) throw;

    // Multi Map
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleQMultiMap.find(k);
    }
    timeTock("Finding QMultiMap");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += SampleStdMultiMap.find(k)->second;
    }
    timeTock("Finding StdMultiMap");
    if (sum > checksum) throw;

    // Hash
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleQHash.find(k);
    }
    timeTock("Finding QHash");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += SampleStdUnorderedMap.find(k)->second;
    }
    timeTock("Finding StdUnorderedMap");
    if (sum > checksum) throw;

    // Multi Hash
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += *SampleQMultiHash.find(k);
    }
    timeTock("Finding QMultiHash");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & k : SampleStdVector)
            sum += SampleStdUnorderedMultiMap.find(k)->second;
    }
    timeTock("Finding StdUnorderedMultiMap");
    if (sum > checksum) throw;

    // List
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & value : SampleStdList)
            sum += value;
    }
    timeTock("Iterating StdList");
    if (sum > checksum) throw;

    // Stack
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & value : SampleQStack)
            sum += value;
    }
    timeTock("Iterating QStack");
    if (sum > checksum) throw;

    // Queue
    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & value : SampleQQueue)
            sum += value;
    }
    timeTock("Iterating QQueue");
    if (sum > checksum) throw;

    timeTick();
    for (j = 0; j < TestCount; ++j)
    {
        sum = 0;
        for (const auto & value : SampleStdDeque)
            sum += value;
    }
    timeTock("Iterating StdDeque");
    if (sum > checksum) throw;

    std::getchar();

    return 0;
}


SampleList_T generateSamplePairsList(int sampleCount)
{
    SampleList_T output;

    output.reserve(sampleCount);

    std::generate_n(std::back_inserter(output),
                    sampleCount,
                    [i = -1]() mutable -> std::pair<Key_T, Value_T>
                    { return { std::rand(), ++i }; });

    return output;
}


QVector<Value_T> generateQVector(const SampleList_T & samplesList)
{
    QVector<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


std::array<Value_T, SampleCount> generateStdArray(const SampleList_T & samplesList)
{
    std::array<Value_T, SampleCount> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output, i = -1] (const auto & pair) mutable
                  { output[++i] = pair.first; });

    return output;
}


std::vector<Value_T> generateStdVector(const SampleList_T & samplesList)
{
    std::vector<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


QList<Value_T> generateQList(const SampleList_T & samplesList)
{
    QList<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


QVarLengthArray<Value_T> generateQVarLengthArray(const SampleList_T & samplesList)
{
    QVarLengthArray<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


QSet<Value_T> generateQSet(const SampleList_T & samplesList)
{
    QSet<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair.first); });

    return output;
}


std::set<Value_T> generateStdSet(const SampleList_T & samplesList)
{
    std::set<Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair.first); });

    return output;
}


std::unordered_set<Value_T> generateStdUnorderedSet(const SampleList_T & samplesList)
{
    std::unordered_set<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair.first); });

    return output;
}


QMap<Key_T, Value_T> generateQMap(const SampleList_T & samplesList)
{
    QMap<Key_T, Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair.first, pair.second); });

    return output;
}


std::map<Key_T, Value_T> generateStdMap(const SampleList_T & samplesList)
{
    std::map<Key_T, Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair); });

    return output;
}


QMultiMap<Key_T, Value_T> generateQMultiMap(const SampleList_T & samplesList)
{
    QMultiMap<Key_T, Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair.first, pair.second); });

    return output;
}


std::multimap<Key_T, Value_T> generateStdMultiMap(const SampleList_T & samplesList)
{
    std::multimap<Key_T, Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair); });

    return output;
}


QHash<Key_T, Value_T> generateQHash(const SampleList_T & samplesList)
{
    QHash<Key_T, Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](auto pair)
                  { output.insert(pair.first, pair.second); });

    return output;
}


std::unordered_map<Key_T, Value_T> generateStdUnorderedMap(const SampleList_T & samplesList)
{
    std::unordered_map<Key_T, Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair); });

    return output;
}


QMultiHash<Key_T, Value_T> generateQMultiHash(const SampleList_T & samplesList)
{
    QMultiHash<Key_T, Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](auto pair)
                  { output.insert(pair.first, pair.second); });

    return output;
}


std::unordered_multimap<Key_T, Value_T> generateStdUnorderedMultiMap(const SampleList_T & samplesList)
{
    std::unordered_multimap<Key_T, Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.insert(pair); });

    return output;
}


std::list<Value_T> generateStdList(const SampleList_T & samplesList)
{
    std::list<Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


QQueue<Value_T> generateQQueue(const SampleList_T & samplesList)
{
    QQueue<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


std::deque<Value_T> generateStdDeque(const SampleList_T & samplesList)
{
    std::deque<Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push_back(pair.first); });

    return output;
}


QStack<Value_T> generateQStack(const SampleList_T & samplesList)
{
    QStack<Value_T> output;
    output.reserve(samplesList.size());

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push(pair.first); });

    return output;
}


std::stack<Value_T> generateStdStack(const SampleList_T & samplesList)
{
    std::stack<Value_T> output;

    std::for_each(samplesList.cbegin(), samplesList.cend(),
                  [&output](const auto & pair)
                  { output.push(pair.first); });

    return output;
}

