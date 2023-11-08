def load_model_from_file(filename):
    """Loads a Wavefront OBJ file."""
    vertices = []
    texture_coords = []
    faces = []

    material = None

    def load_model_from_file(filename):
    """Loads a Wavefront OBJ file."""
    vertices = []
    texture_coords = []
    faces = []

    material = None

    # Open the .obj file for reading
    for line in open(filename, "r"):
        if line.startswith('#'): continue  # Ignore comments
        values = line.split()
        if not values: continue

        if values[0] == 'v':
            vertices.append(list(map(float, values[1:4])))
        elif values[0] == 'vt':
            texture_coords.append(list(map(float, values[1:3])))
        elif values[0] in ('usemtl', 'usemat'):
            material = values[1]
        elif values[0] == 'f':
            # Handle faces with more than 3 vertices (polygon to triangle fan)
            verts = values[1:]
            v0 = verts[0]
            for i in range(1, len(verts) - 1):
                v1 = verts[i]
                v2 = verts[i + 1]
                face = [int(v0.split('/')[0]), int(v1.split('/')[0]), int(v2.split('/')[0])]
                # Process texture if available
                if len(v0.split('/')) > 1 and v0.split('/')[1]:
                    texture = [int(v0.split('/')[1]), int(v1.split('/')[1]), int(v2.split('/')[1])]
                else:
                    texture = [0, 0, 0]  # Default texture indices
                faces.append((face, texture, material))

    return {'vertices': vertices, 'texture': texture_coords, 'faces': faces}