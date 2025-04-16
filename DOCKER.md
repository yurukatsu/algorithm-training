# Using the Docker Environment

This repository includes a Docker environment for algorithm training. By using this environment, you can run your code in a consistent development environment without depending on your local setup.

## Prerequisites

You need to have the following software installed:

- Docker
- Docker Compose
- Visual Studio Code (if you plan to develop using VSCode)
- VSCode Remote - Containers extension (if you plan to develop using VSCode)

## Basic Usage

### 1. Building and Starting the Container

Run the following commands in the repository's root directory:

```bash
docker compose build
docker compose up -d
```

### 2. Connecting to the Container

To execute commands inside the container, use:

```bash
docker compose exec algorithm-training bash
```

This will start a bash shell inside the container.

### 3. Running Scripts

Inside the container, you can run scripts as usual:

```bash
# Running tests
./scripts/alg test quizzes/samples/sample01

# Creating a new project
./scripts/alg create quizzes/atcoder/abc123
```

### 4. Stopping the Container

When you're done working, you can stop the container with:

```bash
docker compose down
```

## Development with VSCode

Using VSCode's Remote Containers feature, you can develop directly inside the container.

### 1. Open the Repository in VSCode

### 2. Execute the "Remote-Containers: Reopen in Container" Command

Open the VSCode command palette (Ctrl+Shift+P) and select "Remote-Containers: Reopen in Container".

### 3. VSCode Starts Inside the Container

This will launch VSCode inside the container, allowing you to edit files and use the terminal.

## Troubleshooting

### Permission Issues

If files generated inside the container are owned by root and cannot be edited on the host, check the user settings in the docker-compose.yml file.

### Compilation Errors

If you encounter compilation errors, verify that the required g++ version and libraries are installed in the container:

```bash
g++ --version
```

### Other Issues

If you encounter other issues, check the Dockerfile to ensure that all necessary packages are installed.
