Gem::Specification.new do |s|
  s.name = %q{libsylph-ruby}
  s.version = '0.01'
  s.author = 'Taku Amano'
  s.date = '2010-04-10'
  s.description = <<-EOF
Ruby bindings for LibSylph.
  EOF
  s.email = 'taku@toi-planning.net'
  s.extensions = [ 'extconf.rb' ]
  s.files = [
    'codeconv.h', 'libsylph-ruby.gemspec', 'extconf.rb',
    'libsylph-ruby.c', *Dir['test/*']
  ]
  s.homepage = 'https://github.com/usualoma/libsylph-ruby'
  s.summary = 'Ruby bindings for LibSylph.'
  s.license = 'MIT'
end

