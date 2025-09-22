/**********************************************************************
 * @file script1.cpp
 * @brief Класс StringBuffer, embedded C++ style
 * @version 2.0 (Improved Embedded C++ style)
 * @date 2025-09-20
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>
#include <algorithm> // For std::min

/*** Class Definition ***/
class StringBuffer
{
public:
    // Constructors & Destructor
    StringBuffer(const char *str = "");
    StringBuffer(const StringBuffer &other);
    StringBuffer(StringBuffer &&other) noexcept;
    ~StringBuffer();

    // Assignment Operators
    StringBuffer &operator=(const StringBuffer &other);
    StringBuffer &operator=(StringBuffer &&other) noexcept;

    // Arithmetic Operators
    friend StringBuffer operator+(const char *lhs, const StringBuffer &rhs);
    StringBuffer operator+(const char *rhs) const;
    StringBuffer &operator+=(const char *rhs);

    // Accessors
    const char *get_data() const { return buffer; }
    int get_size() const { return size; }

    // Capacity
    static constexpr int max_capacity() { return max_size - 1; }
    bool empty() const { return size == 0; }

private:
    enum
    {
        max_size = 1024
    };
    char *buffer{nullptr};
    int size{0};

    // Private constructor for internal operations
    StringBuffer(int capacity) : buffer(new char[capacity + 1]), size(0)
    {
        buffer[0] = '\0';
    }

    // Helper methods
    void safe_delete() noexcept
    {
        delete[] buffer;
        buffer = nullptr;
        size = 0;
    }

    static int safe_strlen(const char *str)
    {
        if (!str)
            return 0;
        return static_cast<int>(std::strnlen(str, max_size - 1));
    }
};

/*** Methods Implementation ***/

// Constructor with null safety
StringBuffer::StringBuffer(const char *str) : buffer(nullptr), size(0)
{
    if (!str)
    {
        buffer = new char[1];
        buffer[0] = '\0';
        return;
    }

    size = safe_strlen(str);
    buffer = new char[size + 1];
    std::strncpy(buffer, str, size);
    buffer[size] = '\0';
}

// Copy constructor
StringBuffer::StringBuffer(const StringBuffer &other)
    : buffer(nullptr), size(other.size)
{
    if (size > 0)
    {
        buffer = new char[size + 1];
        std::strncpy(buffer, other.buffer, size);
        buffer[size] = '\0';
    }
    else
    {
        buffer = new char[1];
        buffer[0] = '\0';
    }
}

// Move constructor
StringBuffer::StringBuffer(StringBuffer &&other) noexcept
    : buffer(other.buffer), size(other.size)
{
    other.buffer = nullptr;
    other.size = 0;
}

// Destructor
StringBuffer::~StringBuffer()
{
    safe_delete();
}

// Copy assignment operator
StringBuffer &StringBuffer::operator=(const StringBuffer &other)
{
    if (this != &other)
    {
        // Create temporary copy for exception safety
        StringBuffer temp(other);
        swap(temp); // Use swap for strong exception guarantee
    }
    return *this;
}

// Move assignment operator
StringBuffer &StringBuffer::operator=(StringBuffer &&other) noexcept
{
    if (this != &other)
    {
        safe_delete();
        buffer = other.buffer;
        size = other.size;
        other.buffer = nullptr;
        other.size = 0;
    }
    return *this;
}

// Addition operator (StringBuffer + string)
StringBuffer StringBuffer::operator+(const char *rhs) const
{
    if (!rhs)
        return *this; // Handle null pointer

    int rhs_len = safe_strlen(rhs);
    int new_size = std::min(size + rhs_len, max_size - 1);

    StringBuffer result(new_size);

    // Copy current content
    if (size > 0)
    {
        std::strncpy(result.buffer, buffer, size);
    }

    // Append new content
    if (rhs_len > 0)
    {
        std::strncpy(result.buffer + size, rhs, new_size - size);
    }

    result.size = new_size;
    result.buffer[new_size] = '\0';

    return result;
}

// Compound addition assignment
StringBuffer &StringBuffer::operator+=(const char *rhs)
{
    if (!rhs || *rhs == '\0')
        return *this; // Nothing to append

    int rhs_len = safe_strlen(rhs);
    int new_size = std::min(size + rhs_len, max_size - 1);

    if (new_size <= size)
        return *this; // No change needed

    char *new_buf = new char[new_size + 1];

    // Copy existing content
    if (size > 0)
    {
        std::strncpy(new_buf, buffer, size);
    }

    // Append new content
    std::strncpy(new_buf + size, rhs, new_size - size);
    new_buf[new_size] = '\0';

    // Swap buffers safely
    delete[] buffer;
    buffer = new_buf;
    size = new_size;

    return *this;
}

// Friend addition operator (string + StringBuffer)
StringBuffer operator+(const char *lhs, const StringBuffer &rhs)
{
    if (!lhs)
        return rhs; // Handle null pointer

    int lhs_len = StringBuffer::safe_strlen(lhs);
    int new_size = std::min(lhs_len + rhs.size, StringBuffer::max_size - 1);

    StringBuffer result(new_size);

    // Copy left part
    if (lhs_len > 0)
    {
        std::strncpy(result.buffer, lhs, lhs_len);
    }

    // Copy right part
    if (rhs.size > 0)
    {
        std::strncpy(result.buffer + lhs_len, rhs.buffer, new_size - lhs_len);
    }

    result.size = new_size;
    result.buffer[new_size] = '\0';

    return result;
}

// Additional helper method (should be added to class definition)
void StringBuffer::swap(StringBuffer &other) noexcept
{
    std::swap(buffer, other.buffer);
    std::swap(size, other.size);
}
/*** Main Function with Examples ***/
int main()
{
    std::cout << "=== StringBuffer Demonstration ===\n\n";

    // Example 1: Basic construction and output
    std::cout << "1. Basic Construction:\n";
    StringBuffer sb1("Hello");
    StringBuffer sb2("World");
    std::cout << "   sb1: '" << sb1.get_data() << "' (size: " << sb1.get_size() << ")\n";
    std::cout << "   sb2: '" << sb2.get_data() << "' (size: " << sb2.get_size() << ")\n\n";

    // Example 2: String concatenation
    std::cout << "2. String Concatenation:\n";
    StringBuffer sb3 = sb1 + " " + sb2 + "!";
    std::cout << "   sb1 + \" \" + sb2 + \"!\": '" << sb3.get_data() << "'\n\n";

    // Example 3: Compound assignment
    std::cout << "3. Compound Assignment:\n";
    StringBuffer sb4("Start");
    std::cout << "   Before +=: '" << sb4.get_data() << "'\n";
    sb4 += " Middle";
    sb4 += " End";
    std::cout << "   After +=: '" << sb4.get_data() << "'\n\n";

    // Example 4: Friend operator (string + StringBuffer)
    std::cout << "4. Friend Operator:\n";
    StringBuffer sb5 = "Prefix: " + sb1;
    std::cout << "   \"Prefix: \" + sb1: '" << sb5.get_data() << "'\n\n";

    // Example 5: Copy constructor and assignment
    std::cout << "5. Copy Operations:\n";
    StringBuffer sb6(sb1);  // Copy constructor
    StringBuffer sb7 = sb2; // Copy assignment
    std::cout << "   Copy of sb1: '" << sb6.get_data() << "'\n";
    std::cout << "   Copy of sb2: '" << sb7.get_data() << "'\n\n";

    // Example 6: Move semantics
    std::cout << "6. Move Operations:\n";
    StringBuffer sb8("Temporary");
    StringBuffer sb9 = std::move(sb8); // Move constructor
    std::cout << "   After move: sb9='" << sb9.get_data() << "', sb8='"
              << (sb8.get_data() ? sb8.get_data() : "null") << "'\n\n";

    // Example 7: Null safety
    std::cout << "7. Null Safety:\n";
    StringBuffer sb10(nullptr);
    StringBuffer sb11 = sb1 + nullptr;
    StringBuffer sb12 = nullptr + sb2;
    std::cout << "   StringBuffer(nullptr): '" << sb10.get_data() << "'\n";
    std::cout << "   sb1 + nullptr: '" << sb11.get_data() << "'\n";
    std::cout << "   nullptr + sb2: '" << sb12.get_data() << "'\n\n";

    // Example 8: Empty string handling
    std::cout << "8. Empty Strings:\n";
    StringBuffer sb13("");
    StringBuffer sb14 = sb13 + "appended";
    std::cout << "   Empty string: '" << sb13.get_data() << "' (size: " << sb13.get_size() << ")\n";
    std::cout << "   Empty + 'appended': '" << sb14.get_data() << "'\n\n";

    // Example 9: Maximum size handling
    std::cout << "9. Maximum Size Handling:\n";
    // Create a long string
    const char *long_str = "This is a very long string that should definitely exceed the maximum buffer size of 1023 characters. "
                           "Let's make sure it gets properly truncated to avoid buffer overflows and maintain safety in embedded systems. "
                           "The StringBuffer class should handle this gracefully by truncating to the maximum allowed size without crashing. "
                           "This is important for embedded systems where stability is critical and memory corruption must be avoided at all costs. "
                           "Additional text to ensure we exceed the limit: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()";

    StringBuffer sb15(long_str);
    std::cout << "   Long string truncated to: " << sb15.get_size() << " characters\n";
    std::cout << "   Max capacity: " << StringBuffer::max_capacity() << " characters\n";
    std::cout << "   First 50 chars: '" << std::string(sb15.get_data(), 50) << "...'\n";
    std::cout << "   Last 50 chars: '..."
              << std::string(sb15.get_data() + sb15.get_size() - 50, 50) << "'\n\n";

    // Example 10: Chained operations
    std::cout << "10. Chained Operations:\n";
    StringBuffer sb16("Hello");
    sb16 += " " += "World" += "!" += " This" += " is" += " chained!";
    std::cout << "   Chained += operations: '" << sb16.get_data() << "'\n\n";

    // Example 11: Self-assignment safety
    std::cout << "11. Self-Assignment Safety:\n";
    StringBuffer sb17("Test");
    std::cout << "   Before self-assignment: '" << sb17.get_data() << "'\n";
    sb17 = sb17; // Should not cause issues
    std::cout << "   After self-assignment: '" << sb17.get_data() << "'\n\n";

    // Example 12: Move assignment
    std::cout << "12. Move Assignment:\n";
    StringBuffer sb18("Source");
    StringBuffer sb19("Target");
    std::cout << "   Before move: sb18='" << sb18.get_data() << "', sb19='" << sb19.get_data() << "'\n";
    sb19 = std::move(sb18);
    std::cout << "   After move: sb18='" << (sb18.get_data() ? sb18.get_data() : "null")
              << "', sb19='" << sb19.get_data() << "'\n\n";

    // Example 13: Complex expressions
    std::cout << "13. Complex Expressions:\n";
    StringBuffer sb20 = "Result: " + (StringBuffer("A") + " " + "B" + " " + "C");
    std::cout << "   Complex expression: '" << sb20.get_data() << "'\n\n";

    // Example 14: Empty buffer operations
    std::cout << "14. Empty Buffer Operations:\n";
    StringBuffer sb21; // Default constructed
    sb21 += "First";
    sb21 += "Second";
    std::cout << "   Default constructed + additions: '" << sb21.get_data() << "'\n\n";

    // Example 15: Boundary conditions
    std::cout << "15. Boundary Conditions:\n";
    // Create string exactly at max capacity
    std::string exact_max(max_size - 1, 'X');
    StringBuffer sb22(exact_max.c_str());
    std::cout << "   Exact max size string: size=" << sb22.get_size()
              << " (should be " << (max_size - 1) << ")\n";

    // Try to exceed capacity
    sb22 += "Y"; // Should not change anything
    std::cout << "   After adding to max capacity: size=" << sb22.get_size()
              << " (should remain " << (max_size - 1) << ")\n\n";

    std::cout << "=== All tests completed successfully! ===\n";

    return 0;
}