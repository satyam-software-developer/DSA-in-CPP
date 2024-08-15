// If the string is empty, return 0
    if (str.length() == 0)
    {
        return 0;
    }

    // Initialize a variable to count spaces
    int spaces = 0;

    // Iterate through the characters of the string
    for (int i = 0; i < str.length(); ++i)
    {
        // If a space character is encountered, increment the spaces count
        if (str[i] == ' ')
        {
            ++spaces;
        }
    }

    // Return the count of spaces plus 1, which represents the number of words
    return spaces + 1;