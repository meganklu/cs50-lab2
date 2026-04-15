# Lab 2 - Megan Lu
COSC050, 26S

## 1.1 Initialize a new git repo
> Initialize lab2 as a git repository. What command did you use for that?

```bash
git init
```
> Make sure that README.md is tracked. What command did you use for that?

```bash
git add README.md
```

Check if the file is under the tracked files of the repository with `git status`.

## 1.2 Obtaining a local copy
> How would you go about cloning the lab2 repo on your local machine? What command would you use for that? 
### **Git clone directly from plink to local machine**
**Best command to use for this prompt.**
```bash
git clone ssh://sp26megan@plink.cs.dartmouth.edu/~/lab2
```
### Directly transfering the directory with secure copy command
This only copies the directory and files in the directiory; it does not clone the repository (does not connect to git as a remote copy).
```bash
scp -r plink:~/lab2 /Users/meganlu/Desktop/COSC050/
```
### Git clone via GitHub
1. Created a new repository in GitHub.
2. Added a remote to the existing lab2 repository in plink.
    ```bash
    git remote add origin git@github.com:meganklu/cs50-lab2.git
    git push -u origin main
    ```
3. Cloned the repository on my local machine.
    ```bash
    git clone https://github.com/meganklu/cs50-lab2.git
    ```
