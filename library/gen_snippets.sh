{
    echo "{"
    find ./ -name "*.cpp" | while read file; do
        filename=$(basename -- "$file") # Get the filename
        snippet_name="${filename%.*}"   # Remove the .cpp extension
        echo "    \"$snippet_name\": {"
        echo "        \"prefix\": \"$snippet_name\","
        echo "        \"body\": ["
        awk '{
            gsub(/\\/, "\\\\");            # Escape double quotes
            gsub(/"/, "\\\"");            # Escape double quotes
            gsub(/\\\\t/, "\\t");            # Escape double quotes
            if (NR != 1) printf ",\n";    # Add a comma before each line except the first
            printf "            \"%s\"", $0;
        } END { printf "\n"; }' "$file"
        echo "        ],"
        echo "        \"description\": \"Snippet generated from $filename\""
        echo "    },"
    done | sed '$ s/},$/}/' # Ensure the last snippet entry doesn't have a trailing comma
    echo "}"
} > snippets.json

mv snippets.json ~/.config/nvim/snippets/Cpp/

