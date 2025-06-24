import random


def generate_vectors(file_path, num_vectors=100000, dim=128):
    with open(file_path, 'w') as f:
        for _ in range(num_vectors):
            vec = [f"{random.uniform(0, 1): 6f}" for _ in range(dim)]
            f.write(" ".join(vec) + "\n")


if __name__ == "__main__":
    generate_vectors("data/vectors.txt", num_vectors=int(100000), dim=1024)
