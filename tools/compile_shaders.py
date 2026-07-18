import sys, os, subprocess


class VersionInfo:
    def __init__(self, version_name: str, version_defines: list[str]) -> None:
        self.version_name = version_name
        self.version_defines = version_defines


def list_shader_files(shader_dir):
    files = []
    for entry in os.listdir(shader_dir):
        full_path = os.path.join(shader_dir, entry)
        if(os.path.isdir(full_path)):
            files.extend(list_shader_files(full_path))
        else:
            files.append(full_path)

    return files


def compile_file(shader_file: str, global_include_path: str):
    if(shader_file.lower().endswith("header.slang")):
        return
    
    if(not shader_file.lower().endswith(".slang")):
        return

    print("Compiling " + shader_file)

    output_file = shader_file + ".spirv"
    command_list = [
        "slangc",
        "-O3",
        "-I",
        global_include_path,
        "-target",
        "spirv",
        "-profile",
        "spirv_1_3",
        "-fvk-use-entrypoint-name",
        "-entry",
        "VertexMain",
        "-entry",
        "FragmentMain",
        shader_file,
        "-o",
        output_file,
    ]
    subprocess.run(command_list)

def compile_files(shader_files: list[str], global_include_path: str):
    for file in shader_files:
        compile_file(file, global_include_path)

def main(workspace_dir: str):
    shader_dir = os.path.join(workspace_dir, "assets/shaders")

    shader_files = list_shader_files(shader_dir)
    compile_files(shader_files, shader_dir)

if __name__ == "__main__":
    main(sys.argv[1])
