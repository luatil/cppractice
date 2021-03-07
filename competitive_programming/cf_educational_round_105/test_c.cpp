#include "c.cpp"

// To make make work again

void test1()
{   
    int test_number = 1;
    const vector<int> box_position = {1, 5, 11, 15};
    const vector<int> special_position = {6, 7, 15};
    const vector<int> solution = {1, 1, 1, 1};
    vector<int> t = create_suffix_array_ver3(box_position, special_position);
    if(solution != t)
    {
        cout << "Test: " << test_number << " failed\n";
        for(const auto&el : t) cout << el << ' ';
        cout << '\n';
    }
    else 
    {
        cout << "Test: " << test_number << " sucess\n";
    }
}

void test_create_boxes_array1()
{   
    int test_number = 1;
    const vector<int> box_position = {1, 5, 11, 15};
    const vector<int> special_position = {6, 7, 15};
    const vector<int> solution = {2, 2, 4};
    vector<int> t = create_number_of_boxes_array_ver2(box_position, special_position);
    if(solution != t)
    {
        cout << "Test create boxes array: " << test_number << " failed\n";
        for(const auto&el : t) cout << el << ' ';
        cout << '\n';
    }
    else 
    {
        cout << "Test create boxes array: " << test_number << " sucess\n";
    }
}


void test2()
{   
    int test_number = 2;
    const vector<int> box_position = {0, 1, 2, 3, 4, 5};
    const vector<int> special_position = {2, 4, 5};
    const vector<int> solution = {3, 3, 3, 2, 2, 1};
    vector<int> t = create_suffix_array_ver3(box_position, special_position);
    if(solution != t)
    {
        cout << "Test: " << test_number << " failed\n";
        for(const auto&el : t) cout << el << ' ';
        cout << '\n';
    }
    else 
    {
        cout << "Test: " << test_number << " sucess\n";
    }
}

int main()
{
    // test_create_boxes_array1();
    test1();
    test2();
}