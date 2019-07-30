find . -exec git check-ignore {} + | xargs -I{} basename {}
