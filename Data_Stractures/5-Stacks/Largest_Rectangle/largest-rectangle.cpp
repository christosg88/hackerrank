#include <iostream>
#include <stack>

typedef unsigned long ulong;
typedef unsigned long long ulonglong;

ulonglong calc_size(std::stack<ulong> &buildings, ulong *heights,
                    ulong new_top_index, ulong new_top);

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of buildings
    ulong num_of_buildings;
    std::cin >> num_of_buildings;

    // the height of each building
    ulong *heights = new ulong[num_of_buildings];

    // for each building
    for (ulong i = 0; i < num_of_buildings; ++i)
    {
        // read the building's height and insert it in the heights array
        std::cin >> heights[i];
    }

    // the stack that will hold the indexes of the buildings
    std::stack<ulong> buildings;

    // the max rectangle that can be drawn
    ulonglong max_rectangle = 0;

    // for each building
    for (ulong i = 0; i < num_of_buildings; ++i)
    {
        // if the stack is empty or the building with the index at the top of
        // the stack is shorter or equal in height with the current building,
        // push the index of the current building at the top of the stack
        if (buildings.empty() || heights[buildings.top()] <= heights[i])
        {
            buildings.push(i);
        }
        // else find the max rectangle of the buildings in stack
        else
        {
            ulonglong rectangle = calc_size(buildings, heights, i, heights[i]);
            if (max_rectangle < rectangle)
                max_rectangle = rectangle;

            buildings.push(i);
        }
    }

    // if there are any buildings left
    if (!buildings.empty())
    {
        ulonglong rectangle = calc_size(buildings, heights, num_of_buildings, 0);
        if (max_rectangle < rectangle)
            max_rectangle = rectangle;
    }

    std::cout << max_rectangle << std::endl;

    delete[] heights;
    return 0;
}

/**
 * Calculate the size of the max rectangle that can be drawn within the
 * buildings
 * @param  buildings     a stack containing the buildings' indexes
 * @param  heights       the array containing the buildings' heights
 * @param  new_top_index the index of the next building (it will be shorter than
 *                       the building at the top of the stack)
 * @param  new_top       the height of the new building
 * @return               the size of the max rectangle that can be drawn
 */
ulonglong calc_size(std::stack<ulong> &buildings, ulong *heights,
                    ulong new_top_index, ulong new_top)
{
    // the size to be returned
    ulonglong max_rectangle = 0;
    // while there are still buildings in the stack and the top building is
    // shorter than the new building
    while (!buildings.empty() && new_top < heights[buildings.top()])
    {
        ulonglong rectangle;
        // the height of the rectangle
        rectangle = heights[buildings.top()];
        buildings.pop();
        // times the base of the rectangle
        rectangle *= (new_top_index - (buildings.empty() ? 0 : buildings.top() + 1));

        if (max_rectangle < rectangle)
            max_rectangle = rectangle;
    }

    return max_rectangle;
}
