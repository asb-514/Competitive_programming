import json
import os

# File paths
input_json = (
    "/Users/shashank/.config/nvim/snippets/Cpp/snippets.json"  # Path to the JSON file
)
output_dir = "./"  # Directory to store the generated files

# Ensure the output directory exists
os.makedirs(output_dir, exist_ok=True)

# Load the JSON file
with open(input_json, "r") as file:
    snippets = json.load(file)

# Generate files from snippets
for snippet_name, snippet_content in snippets.items():
    # Get the snippet body
    body_lines = snippet_content.get("body", [])

    # Create the output file path
    output_file = os.path.join(output_dir, f"{snippet_name}.cpp")

    # Write the body lines to the file
    with open(output_file, "w") as snippet_file:
        snippet_file.write("\n".join(body_lines))

    print(f"Generated file: {output_file}")
