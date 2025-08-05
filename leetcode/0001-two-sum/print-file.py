def read_arrays_from_file(filename):
    """
    Reads arrays from a file where each array is formatted as:
    - First line: size of array (n)
    - Next n lines: elements of the array
    """
    try:
        with open(filename, 'r') as file:
            lines = [line.strip() for line in file.readlines() if line.strip()]
        
        i = 0
        array_count = 1
        
        while i < len(lines):
            try:
                # Read the size of the array
                n = int(lines[i])
                print(f"Array {array_count} (size {n}):")
                
                # Check if we have enough elements
                if i + n >= len(lines):
                    print(f"Warning: Not enough elements for array of size {n}")
                    break
                
                # Read the next n elements
                array = []
                for j in range(1, n + 1):
                    if i + j < len(lines):
                        try:
                            # Try to convert to int first, then float if that fails
                            element = lines[i + j]
                            try:
                                array.append(int(element))
                            except ValueError:
                                array.append(float(element))
                        except ValueError:
                            # If conversion fails, keep as string
                            array.append(element)
                
                # Print the array
                print(f"  {array}")
                print()
                
                # Move to the next array
                i += n + 1
                array_count += 1
                
            except ValueError:
                print(f"Error: Invalid size value '{lines[i]}' at line {i + 1}")
                break
            except IndexError:
                print("Error: Unexpected end of file")
                break
    
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found")
    except Exception as e:
        print(f"Error reading file: {e}")

if __name__ == "__main__":
    read_arrays_from_file("input.txt")